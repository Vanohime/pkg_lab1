#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rgb_line_textEdited(const QString &arg1);

    void on_cmyk_line_textEdited(const QString &arg1);

    void on_hsl_line_textEdited(const QString &arg1);

    void on_actionSelect_color_triggered();

    void on_red_slider_valueChanged(int value);

    void on_green_slider_valueChanged(int value);

    void on_blue_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QColor current_color;
    void paintEvent(QPaintEvent*) override;
    QVector <float> rgb;
    QVector <float> cmyk;
    QVector <float> hsl;
    void update_rgb();
};
#endif // MAINWINDOW_H
