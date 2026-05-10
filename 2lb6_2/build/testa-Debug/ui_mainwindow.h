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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *headerLabel;
    QLabel *correctLabel;
    QTableWidget *correctTable;
    QLabel *errorLabel;
    QTableWidget *errorTable;
    QPushButton *loadButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(644, 386);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        headerLabel = new QLabel(centralwidget);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setGeometry(QRect(200, 10, 200, 31));
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        correctLabel = new QLabel(centralwidget);
        correctLabel->setObjectName("correctLabel");
        correctLabel->setGeometry(QRect(20, 50, 100, 21));
        correctTable = new QTableWidget(centralwidget);
        correctTable->setObjectName("correctTable");
        correctTable->setGeometry(QRect(20, 80, 291, 150));
        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setGeometry(QRect(330, 50, 71, 21));
        errorTable = new QTableWidget(centralwidget);
        errorTable->setObjectName("errorTable");
        errorTable->setGeometry(QRect(330, 80, 281, 150));
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");
        loadButton->setGeometry(QRect(140, 270, 140, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 644, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        headerLabel->setText(QCoreApplication::translate("MainWindow", "<b>\320\222\321\213\320\262\320\276\320\264 \320\264\320\260\320\275\320\275\321\213\321\205</b>", nullptr));
        correctLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\321\200\320\265\320\272\321\202\320\275\321\213\320\265", nullptr));
        errorLabel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\270", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214.json", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
