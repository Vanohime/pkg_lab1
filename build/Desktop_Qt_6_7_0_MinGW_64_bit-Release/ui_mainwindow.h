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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelect_color;
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *rgb_line;
    QLabel *label_2;
    QLineEdit *cmyk_line;
    QLabel *label_3;
    QLineEdit *hsl_line;
    QLabel *message_label;
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
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(240, 90, 341, 261));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        rgb_line = new QLineEdit(widget);
        rgb_line->setObjectName("rgb_line");

        verticalLayout->addWidget(rgb_line);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        cmyk_line = new QLineEdit(widget);
        cmyk_line->setObjectName("cmyk_line");

        verticalLayout->addWidget(cmyk_line);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        hsl_line = new QLineEdit(widget);
        hsl_line->setObjectName("hsl_line");

        verticalLayout->addWidget(hsl_line);


        verticalLayout_2->addLayout(verticalLayout);

        message_label = new QLabel(widget);
        message_label->setObjectName("message_label");

        verticalLayout_2->addWidget(message_label);

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
        label->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "CMYK", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "HSL", nullptr));
        message_label->setText(QString());
        menuSelect_color->setTitle(QCoreApplication::translate("MainWindow", "Select color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
