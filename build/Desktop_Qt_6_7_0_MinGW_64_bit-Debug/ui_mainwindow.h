/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelect_color;
    QWidget *centralwidget;
    QLabel *message_label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *rgb_line;
    QLabel *label_2;
    QLineEdit *cmyk_line;
    QLabel *label_3;
    QLineEdit *hsl_line;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QSlider *red_slider;
    QSlider *green_slider;
    QSlider *blue_slider;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QLabel *red_sl_val;
    QLabel *green_sl_val;
    QLabel *blue_sl_val;
    QMenuBar *menubar;
    QMenu *menuSelect_color;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionSelect_color = new QAction(MainWindow);
        actionSelect_color->setObjectName("actionSelect_color");
        actionSelect_color->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        message_label = new QLabel(centralwidget);
        message_label->setObjectName("message_label");
        message_label->setGeometry(QRect(210, 330, 311, 51));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(210, 90, 321, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        rgb_line = new QLineEdit(layoutWidget);
        rgb_line->setObjectName("rgb_line");

        verticalLayout->addWidget(rgb_line);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        cmyk_line = new QLineEdit(layoutWidget);
        cmyk_line->setObjectName("cmyk_line");

        verticalLayout->addWidget(cmyk_line);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        hsl_line = new QLineEdit(layoutWidget);
        hsl_line->setObjectName("hsl_line");

        verticalLayout->addWidget(hsl_line);


        verticalLayout_2->addLayout(verticalLayout);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(210, 370, 181, 131));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        red_slider = new QSlider(layoutWidget1);
        red_slider->setObjectName("red_slider");
        red_slider->setMaximum(255);
        red_slider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(red_slider);

        green_slider = new QSlider(layoutWidget1);
        green_slider->setObjectName("green_slider");
        green_slider->setMaximum(255);
        green_slider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(green_slider);

        blue_slider = new QSlider(layoutWidget1);
        blue_slider->setObjectName("blue_slider");
        blue_slider->setMaximum(255);
        blue_slider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(blue_slider);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(470, 370, 81, 131));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName("label_5");

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName("label_6");

        verticalLayout_4->addWidget(label_6);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(400, 370, 61, 131));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        red_sl_val = new QLabel(widget);
        red_sl_val->setObjectName("red_sl_val");

        verticalLayout_5->addWidget(red_sl_val);

        green_sl_val = new QLabel(widget);
        green_sl_val->setObjectName("green_sl_val");

        verticalLayout_5->addWidget(green_sl_val);

        blue_sl_val = new QLabel(widget);
        blue_sl_val->setObjectName("blue_sl_val");

        verticalLayout_5->addWidget(blue_sl_val);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuSelect_color = new QMenu(menubar);
        menuSelect_color->setObjectName("menuSelect_color");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSelect_color->menuAction());
        menuSelect_color->addAction(actionSelect_color);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSelect_color->setText(QCoreApplication::translate("MainWindow", "Color picker", nullptr));
        message_label->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "CMYK", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "HSL", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        red_sl_val->setText(QString());
        green_sl_val->setText(QString());
        blue_sl_val->setText(QString());
        menuSelect_color->setTitle(QCoreApplication::translate("MainWindow", "Select color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
