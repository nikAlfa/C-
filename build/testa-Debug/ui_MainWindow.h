/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *photoLabel;
    QLabel *photoPreviewLabel;
    QPushButton *loadPhotoButton;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *surnameLabel;
    QLineEdit *surnameEdit;
    QLabel *nicknameLabel;
    QLineEdit *nicknameEdit;
    QLabel *idKeyLabel;
    QLineEdit *idKeyEdit;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *serversLabel;
    QCheckBox *europeCheckBox;
    QCheckBox *asiaCheckBox;
    QCheckBox *americaCheckBox;
    QPushButton *registerButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(542, 383);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow { background-color: #2c3e50; }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(140, 10, 200, 40));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1;"));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        photoLabel = new QLabel(centralwidget);
        photoLabel->setObjectName("photoLabel");
        photoLabel->setGeometry(QRect(20, 70, 40, 25));
        photoLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1; font-size: 12px;"));
        photoPreviewLabel = new QLabel(centralwidget);
        photoPreviewLabel->setObjectName("photoPreviewLabel");
        photoPreviewLabel->setGeometry(QRect(80, 60, 100, 100));
        photoPreviewLabel->setStyleSheet(QString::fromUtf8("background-color: #34495e;"));
        photoPreviewLabel->setFrameShape(QFrame::Shape::Box);
        photoPreviewLabel->setScaledContents(true);
        loadPhotoButton = new QPushButton(centralwidget);
        loadPhotoButton->setObjectName("loadPhotoButton");
        loadPhotoButton->setGeometry(QRect(80, 170, 100, 30));
        loadPhotoButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: #1abc9c; color: #2c3e50; border-radius: 5px; padding: 5px; font-weight: bold; } QPushButton:hover { background-color: #16a085; }"));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(210, 60, 80, 25));
        nameLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1; font-size: 12px;"));
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(250, 60, 200, 30));
        nameEdit->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: #34495e; color: #ecf0f1; border: 1px solid #1abc9c; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 2px solid #1abc9c; }"));
        surnameLabel = new QLabel(centralwidget);
        surnameLabel->setObjectName("surnameLabel");
        surnameLabel->setGeometry(QRect(210, 90, 80, 25));
        surnameLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1; font-size: 12px;"));
        surnameEdit = new QLineEdit(centralwidget);
        surnameEdit->setObjectName("surnameEdit");
        surnameEdit->setGeometry(QRect(280, 90, 200, 30));
        surnameEdit->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: #34495e; color: #ecf0f1; border: 1px solid #1abc9c; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 2px solid #1abc9c; }"));
        nicknameLabel = new QLabel(centralwidget);
        nicknameLabel->setObjectName("nicknameLabel");
        nicknameLabel->setGeometry(QRect(210, 120, 80, 25));
        nicknameLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1; font-size: 12px;"));
        nicknameEdit = new QLineEdit(centralwidget);
        nicknameEdit->setObjectName("nicknameEdit");
        nicknameEdit->setGeometry(QRect(270, 120, 200, 30));
        nicknameEdit->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: #34495e; color: #ecf0f1; border: 1px solid #1abc9c; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 2px solid #1abc9c; }"));
        idKeyLabel = new QLabel(centralwidget);
        idKeyLabel->setObjectName("idKeyLabel");
        idKeyLabel->setGeometry(QRect(210, 160, 80, 25));
        idKeyLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1; font-size: 12px;"));
        idKeyEdit = new QLineEdit(centralwidget);
        idKeyEdit->setObjectName("idKeyEdit");
        idKeyEdit->setGeometry(QRect(270, 160, 200, 30));
        idKeyEdit->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: #34495e; color: #ecf0f1; border: 1px solid #1abc9c; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 2px solid #1abc9c; }"));
        emailLabel = new QLabel(centralwidget);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(210, 200, 80, 25));
        emailLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1; font-size: 12px;"));
        emailEdit = new QLineEdit(centralwidget);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setGeometry(QRect(260, 200, 200, 30));
        emailEdit->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: #34495e; color: #ecf0f1; border: 1px solid #1abc9c; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 2px solid #1abc9c; }"));
        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(210, 240, 80, 25));
        passwordLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1; font-size: 12px;"));
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(260, 240, 200, 30));
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit { background-color: #34495e; color: #ecf0f1; border: 1px solid #1abc9c; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 2px solid #1abc9c; }"));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        serversLabel = new QLabel(centralwidget);
        serversLabel->setObjectName("serversLabel");
        serversLabel->setGeometry(QRect(40, 280, 80, 25));
        serversLabel->setStyleSheet(QString::fromUtf8("color: #ecf0f1; font-size: 12px;"));
        europeCheckBox = new QCheckBox(centralwidget);
        europeCheckBox->setObjectName("europeCheckBox");
        europeCheckBox->setGeometry(QRect(40, 320, 70, 25));
        europeCheckBox->setStyleSheet(QString::fromUtf8("color: #ecf0f1;"));
        asiaCheckBox = new QCheckBox(centralwidget);
        asiaCheckBox->setObjectName("asiaCheckBox");
        asiaCheckBox->setGeometry(QRect(130, 320, 70, 25));
        asiaCheckBox->setStyleSheet(QString::fromUtf8("color: #ecf0f1;"));
        americaCheckBox = new QCheckBox(centralwidget);
        americaCheckBox->setObjectName("americaCheckBox");
        americaCheckBox->setGeometry(QRect(190, 320, 80, 25));
        americaCheckBox->setStyleSheet(QString::fromUtf8("color: #ecf0f1;"));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(320, 300, 180, 40));
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: #1abc9c; color: #2c3e50; border-radius: 5px; padding: 10px; font-weight: bold; font-size: 14px; } QPushButton:hover { background-color: #16a085; }"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        photoLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\202\320\276", nullptr));
        photoPreviewLabel->setText(QString());
        loadPhotoButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\230\320\262\320\260\320\275", nullptr));
        surnameLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        surnameEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\230\320\262\320\260\320\275\320\276\320\262", nullptr));
        nicknameLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\270\320\272\320\275\320\265\320\271\320\274", nullptr));
        nicknameEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "ivan123", nullptr));
        idKeyLabel->setText(QCoreApplication::translate("MainWindow", "ID-Key", nullptr));
        idKeyEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "A111-11A-A", nullptr));
        emailLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        emailEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "example@domain.com", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214 (\320\274\320\270\320\275. 6 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262, \320\261\321\203\320\272\320\262\320\260+\321\206\320\270\321\204\321\200\320\260)", nullptr));
        serversLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\265\321\200\320\260:", nullptr));
        europeCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\225\320\262\321\200\320\276\320\277\320\260", nullptr));
        asiaCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\220\320\267\320\270\321\217", nullptr));
        americaCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\220\320\274\320\265\321\200\320\270\320\272\320\260", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
