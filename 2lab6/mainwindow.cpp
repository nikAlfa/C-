#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Задаём JSON-файл по умолчанию
    ui->jsonFileLineEdit->setText("objects.json");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadTxtButton_clicked()
{
    QString txtFile = QFileDialog::getOpenFileName(this,
                                                   "Выберите TXT файл", QString(), "Text files (*.txt)");
    if (txtFile.isEmpty())
        return;

    QFile file(txtFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QTextStream in(&file);
    QStringList lines;
    while (!in.atEnd())
        lines << in.readLine();
    file.close();

    // Заполняем поля (если строк меньше 4, недостающие останутся пустыми)
    ui->nameEdit->setText(lines.value(0).trimmed());
    ui->surnameEdit->setText(lines.value(1).trimmed());
    ui->heightEdit->setText(lines.value(2).trimmed());
    ui->weightEdit->setText(lines.value(3).trimmed());
}

void MainWindow::on_okButton_clicked()
{
    QString fileName = ui->jsonFileLineEdit->text().trimmed();
    if (fileName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this,
                                                "Сохранить JSON", "objects.json", "JSON (*.json)");
        if (fileName.isEmpty())
            return;
        ui->jsonFileLineEdit->setText(fileName);
    }

    appendToJsonFile(fileName,
                     ui->nameEdit->text(),
                     ui->surnameEdit->text(),
                     ui->heightEdit->text(),
                     ui->weightEdit->text());
    QMessageBox::information(this, "Готово", "Объект добавлен в файл");
}

void MainWindow::appendToJsonFile(const QString &fileName,
                                  const QString &name,
                                  const QString &surname,
                                  const QString &heightStr,
                                  const QString &weightStr)
{
    QJsonArray array;

    // Читаем существующий массив, если файл уже есть
    QFile file(fileName);
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        if (doc.isArray())
            array = doc.array();
        file.close();
    }

    // Создаём новый объект (все поля сохраняем как строки, Program2 определит ошибки)
    QJsonObject obj;
    obj["имя"] = name;
    obj["фамилия"] = surname;
    obj["рост"] = heightStr;
    obj["вес"] = weightStr;
    array.append(obj);

    // Записываем обратно
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(nullptr, "Ошибка", "Не удалось записать файл");
        return;
    }
    file.write(QJsonDocument(array).toJson());
    file.close();
}
