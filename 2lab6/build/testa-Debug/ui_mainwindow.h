/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *surnameLabel;
    QLineEdit *surnameEdit;
    QLabel *heightLabel;
    QLineEdit *heightEdit;
    QLabel *weightLabel;
    QLineEdit *weightEdit;
    QPushButton *loadTxtButton;
    QPushButton *okButton;
    QLineEdit *jsonFileLineEdit;
    QLabel *jsonLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(521, 397);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(20, 20, 251, 31));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(20, 70, 51, 21));
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(60, 70, 200, 25));
        surnameLabel = new QLabel(centralwidget);
        surnameLabel->setObjectName("surnameLabel");
        surnameLabel->setGeometry(QRect(20, 110, 61, 21));
        surnameEdit = new QLineEdit(centralwidget);
        surnameEdit->setObjectName("surnameEdit");
        surnameEdit->setGeometry(QRect(80, 110, 200, 25));
        heightLabel = new QLabel(centralwidget);
        heightLabel->setObjectName("heightLabel");
        heightLabel->setGeometry(QRect(20, 150, 41, 21));
        heightEdit = new QLineEdit(centralwidget);
        heightEdit->setObjectName("heightEdit");
        heightEdit->setGeometry(QRect(60, 150, 200, 25));
        weightLabel = new QLabel(centralwidget);
        weightLabel->setObjectName("weightLabel");
        weightLabel->setGeometry(QRect(20, 190, 31, 21));
        weightEdit = new QLineEdit(centralwidget);
        weightEdit->setObjectName("weightEdit");
        weightEdit->setGeometry(QRect(50, 190, 200, 25));
        loadTxtButton = new QPushButton(centralwidget);
        loadTxtButton->setObjectName("loadTxtButton");
        loadTxtButton->setGeometry(QRect(300, 60, 80, 61));
        okButton = new QPushButton(centralwidget);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(300, 130, 80, 71));
        jsonFileLineEdit = new QLineEdit(centralwidget);
        jsonFileLineEdit->setObjectName("jsonFileLineEdit");
        jsonFileLineEdit->setGeometry(QRect(30, 230, 200, 25));
        jsonLabel = new QLabel(centralwidget);
        jsonLabel->setObjectName("jsonLabel");
        jsonLabel->setGeometry(QRect(240, 230, 51, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 521, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "<b>\320\235\320\276\320\262\321\213\320\271 \320\276\320\261\321\212\320\265\320\272\321\202</b>", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217:", nullptr));
        surnameLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        heightLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\321\201\321\202:", nullptr));
        weightLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\201:", nullptr));
        loadTxtButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267 .TXT", nullptr));
        okButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\272", nullptr));
        jsonFileLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\270\320\274\321\217_\321\204\320\260\320\271\320\273\320\260.json", nullptr));
        jsonLabel->setText(QCoreApplication::translate("MainWindow", ".json", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
