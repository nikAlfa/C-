#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QStandardPaths>
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QEvent>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , selectedPhotoPath("")
    , isPhotoLoaded(false)
{
    ui->setupUi(this);

    // Двойной клик – очистка поля
    QList<QLineEdit*> lineEdits = this->findChildren<QLineEdit*>();
    for (QLineEdit *le : lineEdits) {
        le->installEventFilter(this);
    }

    // Загрузка изображения по умолчанию
    QPixmap defaultPixmap(":/default.png");
    if (!defaultPixmap.isNull()) {
        ui->photoPreviewLabel->setPixmap(defaultPixmap.scaled(100, 100, Qt::KeepAspectRatio));
    } else {
        // Альтернатива – показать текст
        ui->photoPreviewLabel->setText("[Фото]");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        QLineEdit *lineEdit = qobject_cast<QLineEdit*>(obj);
        if (lineEdit) {
            lineEdit->clear();
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_loadPhotoButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите фото", "",
                                                    "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            ui->photoPreviewLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
            selectedPhotoPath = fileName;
            isPhotoLoaded = true;
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось загрузить изображение.");
        }
    }
}

bool MainWindow::validateInputs()
{
    QRegularExpression nameRegex("^[A-Za-zА-Яа-я]+$");
    QRegularExpression nicknameRegex("^[A-Za-z0-9]+$");
    QRegularExpression idRegex("^[A-Za-z]\\d{3}-\\d{2}[A-Za-z]-[A-Za-z]$");
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    QRegularExpression passwordRegex("^.{6,}$");

    QString name = ui->nameEdit->text().trimmed();
    QString surname = ui->surnameEdit->text().trimmed();
    QString nickname = ui->nicknameEdit->text().trimmed();
    QString idKey = ui->idKeyEdit->text().trimmed();
    QString email = ui->emailEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if (name.isEmpty() || surname.isEmpty() || nickname.isEmpty() ||
        idKey.isEmpty() || email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
        return false;
    }

    if (!nameRegex.match(name).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Имя должно содержать только буквы.");
        return false;
    }
    if (!nameRegex.match(surname).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Фамилия должна содержать только буквы.");
        return false;
    }
    if (!nicknameRegex.match(nickname).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Никнейм может содержать только буквы и цифры.");
        return false;
    }
    if (!idRegex.match(idKey).hasMatch()) {
        QMessageBox::warning(this, "Ошибка",
                             "ID-Key должен соответствовать формату: А111-11А-А\n"
                             "(буква, три цифры, дефис, две цифры, буква, дефис, буква)");
        return false;
    }
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Введите корректный email.");
        return false;
    }
    if (!passwordRegex.match(password).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Пароль должен содержать не менее 6 символов.");
        return false;
    }

    bool hasLetter = false, hasDigit = false;
    for (QChar ch : password) {
        if (ch.isLetter()) hasLetter = true;
        else if (ch.isDigit()) hasDigit = true;
    }
    if (!hasLetter || !hasDigit) {
        QMessageBox::warning(this, "Ошибка", "Пароль должен содержать хотя бы одну букву и одну цифру.");
        return false;
    }

    return true;
}

bool MainWindow::isNicknameUnique(const QString &nickname)
{
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir accountsDir(desktopPath + "/Accounts");
    if (!accountsDir.exists())
        return true;
    return !accountsDir.exists(nickname);
}

QString MainWindow::encryptPassword(const QString &password)
{
    QByteArray data = password.toUtf8();
    char key = 0x5A;
    for (int i = 0; i < data.size(); ++i)
        data[i] = data[i] ^ key;
    return data.toHex();
}

void MainWindow::saveAccount()
{
    QString nickname = ui->nicknameEdit->text().trimmed();
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString userFolderPath = desktopPath + "/Accounts/" + nickname;

    QDir dir;
    if (!dir.mkpath(userFolderPath)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось создать папку пользователя.");
        return;
    }

    QString destPhoto = userFolderPath + "/avatar.png";
    if (isPhotoLoaded && !selectedPhotoPath.isEmpty())
        QFile::copy(selectedPhotoPath, destPhoto);
    else
        QFile::copy(":/default.png", destPhoto);

    QJsonObject json;
    json["name"] = ui->nameEdit->text().trimmed();
    json["surname"] = ui->surnameEdit->text().trimmed();
    json["nickname"] = nickname;
    json["email"] = ui->emailEdit->text().trimmed();
    json["id_key"] = ui->idKeyEdit->text().trimmed();

    QStringList servers;
    if (ui->europeCheckBox->isChecked()) servers << "Европа";
    if (ui->asiaCheckBox->isChecked()) servers << "Азия";
    if (ui->americaCheckBox->isChecked()) servers << "Америка";
    json["servers"] = QJsonArray::fromStringList(servers);

    QFile jsonFile(userFolderPath + "/data.json");
    if (jsonFile.open(QIODevice::WriteOnly)) {
        jsonFile.write(QJsonDocument(json).toJson());
        jsonFile.close();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить data.json");
        return;
    }

    QString email = ui->emailEdit->text().trimmed();
    QString encrypted = encryptPassword(ui->passwordEdit->text());
    QFile txtFile(userFolderPath + "/credentials.txt");
    if (txtFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&txtFile);
        out << email << "/" << encrypted;
        txtFile.close();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить credentials.txt");
        return;
    }

    QMessageBox::information(this, "Успех",
                             "Регистрация прошла успешно!\n"
                             "Данные сохранены в папке:\n" + userFolderPath);
}

void MainWindow::on_registerButton_clicked()
{
    QString nickname = ui->nicknameEdit->text().trimmed();
    if (!isNicknameUnique(nickname)) {
        QMessageBox::warning(this, "Ошибка", "Указанный никнейм уже занят. Выберите другой.");
        return;
    }

    if (validateInputs())
        saveAccount();
}
