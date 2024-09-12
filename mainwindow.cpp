#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QString>
#include <QRegularExpression>
#include <QPaintEvent>
#include <QColorDialog>
#include <QPalette>

float roundToTwoDecimals(float value) {
    return std::round(value * 100) / 100;
}

QVector<float> string_to_vector(QString s, bool& is_valid) {
    QVector<float> res;
    if(s == "") {
        is_valid = false;
        return res;
    }
    for (auto c : s) {
        if((c > '9' || c < '0') && c != '%' && c != ' ' && c != ',' && c!= '.'){
            is_valid = false;
            return res;
        }
    }
    if((s[0] < '0' || s[0] > '9') && s[0] != ' '){
        is_valid = false;
        return res;
    }

    QString cleanedInput = s;
    cleanedInput.replace(QRegularExpression("[,\\s]+"), " ");
    cleanedInput = cleanedInput.trimmed();

    QStringList parts = cleanedInput.split(' ',  Qt::SkipEmptyParts);

    for (const QString &part : parts) {
        bool ok;
        double number = part.toDouble(&ok);
        if (ok) {
            res.push_back(number);
        } else {
            is_valid = false;
            return res;
        }
    }
    if(res.empty())
        is_valid = false;
    return res;
}

QString vector_to_string(QVector<float> arr, bool& is_valid) {
    QString ans;
    if (arr.empty()){
        is_valid = false;
        return ans;
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = roundToTwoDecimals(arr[i]);
    }
    for(auto n : arr) {
        if(!(n - (int)n)){
            ans += QString::number((int)n);
        }
        else {
             ans += QString::number(n);
        }
        ans += ", ";
    }
    ans.truncate(ans.lastIndexOf(QChar(',')));
    return ans;
}

QVector <float> rgb_to_cmyk(const QVector <float>& rgb_arg) {
    QVector<float> cmyk_1(4, 0.0);
    float r = rgb_arg[0];
    float g = rgb_arg[1];
    float b = rgb_arg[2];
    if (r == 0 && g == 0 && b == 0) {
        cmyk_1[3] = 1;
        return cmyk_1;
    }
    r /= 255.0;
    g /= 255.0;
    b /= 255.0;
    float k = 1 - std::max({r, g, b});
    cmyk_1[0] = (1 - r - k) / (1 - k);
    cmyk_1[1] = (1 - g - k) / (1 - k);
    cmyk_1[2] = (1 - b - k) / (1 - k);
    cmyk_1[3] = k;
    return cmyk_1;
}

QVector <float> cmyk_to_rgb(const QVector <float>& arg) {
    QVector<float> res(3);
    res[0] = std::round(255 * (1 - arg[0]) * (1 - arg[3]));
    res[1] = std::round(255 * (1 - arg[1]) * (1 - arg[3]));
    res[2] = std::round(255 * (1 - arg[2]) * (1 - arg[3]));
    return res;
}

QVector <float> rgb_to_hsl (const QVector <float>& arg){
    QVector<float> res(3, 0.0);
    float r = arg[0] / 255.0;
    float g = arg[1] / 255.0;
    float b = arg[2] / 255.0;

    float M = std::max({r, g, b});
    float m = std::min({r, g, b});

    float c = M - m;

    if(c)
    {
        float h_dash;
        if(M == r) {
            h_dash =(g - b) / c  + (g < b ? 6 : 0);
        }
        if (M == g) {
            h_dash = ((b - r)/ c) + 2;
        }
        if (M == b) {
            h_dash = ((r - g)/c) + 4;
        }
        res[0] = 60 * h_dash;
        if(res[0] < 0)
            res[0] += 360;
    }
    res[2] = (M + m) / 2;
    if(c)
        res[1] = c / (1 - abs(2*res[2] - 1));
    else
        res[1] = 0;
    return res;
}

QVector <float> hsl_to_rgb (const QVector <float>& arg){
   QVector <float> res(3, 0);
   float c = (1 - abs(2*arg[2] - 1)) * arg[1];
   float h = arg[0] / 60;
   float h_m = h;
   while (h_m >=2)
       h_m -= 2;
   float x = c * (1 - abs (h_m - 1));

   if (h >=0 && h <= 1){
       res[0] = c;
       res[1] = x;
   }
   if (h >=1 && h <= 2){
       res[0] = x;
       res[1] = c;
   }
   if (h >=2 && h <= 3){
       res[1] = c;
       res[2] = x;
   }
   if (h >=3 && h <= 4){
       res[2] = c;
       res[1] = x;
   }
   if (h >=4 && h <= 5){
       res[0] = x;
       res[2] = c;
   }
   if (h >=5 && h <= 6){
       res[0] = c;
       res[2] = x;
   }
   float m = arg[2]  - c/2;
   res[0] += m;
   res[0] *= 255;
   res[0] = std::round(res[0]);
   res[1] += m;
   res[1] *= 255;
   res[1] = std::round(res[1]);
   res[2] += m;
   res[2] *= 255;
   res[2] = std::round(res[2]);
   return res;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    current_color = Qt::white;
    rgb = QVector<float>(3, 0);
    hsl = QVector<float>(3, 0);
    cmyk = QVector<float>(4, 0);
    this->setAutoFillBackground(true);
    ui->cmyk_line->setAutoFillBackground(true);
    ui->rgb_line->setAutoFillBackground(true);
    ui->hsl_line->setAutoFillBackground(true);
    ui->red_sl_val->setText(QString::number(ui->red_slider->value()));
    ui->green_sl_val->setText(QString::number(ui->green_slider->value()));
    ui->blue_sl_val->setText(QString::number(ui->blue_slider->value()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPalette pal;
    pal.setColor(QPalette :: Window, current_color);
    this->setPalette(pal);
    QString colorStyleW = "color: rgb(255, 255, 255);";
    QString colorStyleB = "color: rgb(0, 0, 0);";
    if (cmyk[3] > 0.50) {
        ui->label->setStyleSheet(colorStyleW);
        ui->label_2->setStyleSheet(colorStyleW);
        ui->label_3->setStyleSheet(colorStyleW);
        ui->message_label->setStyleSheet(colorStyleW);
    } else {
        ui->label->setStyleSheet(colorStyleB);
        ui->label_2->setStyleSheet(colorStyleB);
        ui->label_3->setStyleSheet(colorStyleB);
        ui->message_label->setStyleSheet(colorStyleB);
    }

}

void MainWindow::update_rgb()
{
    bool ok1 = true;
    QString c = vector_to_string(rgb, ok1);
    if (ok1)
        ui->rgb_line->setText(c);
    on_rgb_line_textEdited(c);
}


void MainWindow::on_rgb_line_textEdited(const QString &arg1)
{
    ui->message_label->setText("");
    bool ok = true;
    QVector<float> nums(string_to_vector(arg1, ok));
    if(!ok)
        return;
    if(nums.size()!= 3)
        return;
    for(int i = 0; i < 3; i++){
        if(nums[i] > 255 || nums[i] < 0)
            return;
    }

    rgb = nums;
    cmyk = rgb_to_cmyk(rgb);
    bool ok1 = true;
    QString c = vector_to_string(cmyk, ok1);
    if (ok1)
        ui->cmyk_line->setText(c);
    current_color = QColor (nums[0], nums[1], nums[2]);

    hsl = rgb_to_hsl(rgb);
    bool ok2 = true;
    QString c1 = vector_to_string(hsl, ok2);
    if(ok2)
        ui->hsl_line->setText(c1);
    update();
}


void MainWindow::on_cmyk_line_textEdited(const QString &arg1)
{
    bool ok = true;
    QVector<float> nums(string_to_vector(arg1, ok));
    if(!ok)
        return;
    if(nums.size()!= 4)
        return;
    for(int i = 0; i < 4; i++){
        if(nums[i] > 1 || nums[i] < 0)
            return;
    }
    cmyk = nums;
    rgb = cmyk_to_rgb(cmyk);
    bool ok1 = true;
    QString c = vector_to_string(rgb, ok1);
    if (ok1)
        ui->rgb_line->setText(c);
    QColor n;
    n.setCmykF(cmyk[0], cmyk[1], cmyk[2], cmyk[3]);
    current_color = n;

    hsl = rgb_to_hsl(rgb);
    bool ok2 = true;
    QString c1 = vector_to_string(hsl, ok2);
    if(ok2)
        ui->hsl_line->setText(c1);

    QVector<float> test(rgb_to_cmyk(rgb));
    for(int i = 0; i < 4; i++){
        if(abs(test[i] - cmyk[i]) > 0.01)
            ui->message_label->setText("Внимание! Произойдет потеря цвета");
        else
            ui->message_label->setText("");

    }
    update();
}


void MainWindow::on_hsl_line_textEdited(const QString &arg1)
{
    ui->message_label->setText("");
    bool ok = true;
    QVector<float> nums(string_to_vector(arg1, ok));
    if(!ok)
        return;
    if(nums.size()!= 3)
        return;
    if(nums[0] > 360 || nums[0] < 0)
        return;
    if(nums[1] > 1 || nums[1] < 0)
        return;
    if(nums[2] > 1 || nums[2] < 0)
        return;

    hsl = nums;
    /*QColor col;
    col.setHsl(hsl[0], hsl[1], hsl[2]);
    current_color = col;*/
    current_color = QColor::fromHslF(hsl[0]/360, hsl[1], hsl[2]);

    rgb = hsl_to_rgb(hsl);
    bool ok1 = true;
    QString c = vector_to_string(rgb, ok1);
    if (ok1)
        ui->rgb_line->setText(c);

    //current_color = QColor(rgb[0], rgb[1], rgb[2]);

    cmyk = rgb_to_cmyk(rgb);
    bool ok2 = true;
    QString c1 = vector_to_string(cmyk, ok2);
    if (ok2)
        ui->cmyk_line->setText(c1);
    update();
}


void MainWindow::on_actionSelect_color_triggered()
{
    ui->message_label->setText("");
    current_color = QColorDialog::getColor(current_color, this, "Выберите новый цвет");
    rgb[0] = current_color.red();
    rgb[1] = current_color.green();
    rgb[2] = current_color.blue();
    bool ok = true;
    QString s = vector_to_string(rgb, ok);
    ui->rgb_line->setText(s);
    on_rgb_line_textEdited(s);
    update();
}


void MainWindow::on_red_slider_valueChanged(int value)
{
    ui->red_sl_val->setText(QString::number(ui->red_slider->value()));
    rgb[0] = value;
    update_rgb();
}


void MainWindow::on_green_slider_valueChanged(int value)
{
    ui->green_sl_val->setText(QString::number(ui->green_slider->value()));
    rgb[1] = value;
    update_rgb();
}


void MainWindow::on_blue_slider_valueChanged(int value)
{
    ui->blue_sl_val->setText(QString::number(ui->blue_slider->value()));
    rgb[2] = value;
    update_rgb();
}

