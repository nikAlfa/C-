#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Настройка таблицы "Корректные"
    ui->correctTable->setColumnCount(4);
    ui->correctTable->setHorizontalHeaderLabels({"Имя", "Фамилия", "Рост", "Вес"});
    ui->correctTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Настройка таблицы "Ошибки"
    ui->errorTable->setColumnCount(4);
    ui->errorTable->setHorizontalHeaderLabels({"Имя", "Фамилия", "Рост", "Вес"});
    ui->errorTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString jsonFile = QFileDialog::getOpenFileName(this,
                                                    "Выберите JSON файл", QString(), "JSON (*.json)");
    if (jsonFile.isEmpty())
        return;

    QFile file(jsonFile);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isArray()) {
        QMessageBox::warning(this, "Ошибка", "Файл должен содержать JSON-массив");
        return;
    }

    QJsonArray allObjects = doc.array();
    QJsonArray correctArray;
    QJsonArray brokenArray;

    for (const QJsonValue &val : allObjects) {
        if (val.isObject()) {
            QJsonObject obj = val.toObject();
            if (isValidObject(obj))
                correctArray.append(obj);
            else
                brokenArray.append(obj);
        } else {
            brokenArray.append(val);
        }
    }

    // Преобразуем QJsonArray в QList<QJsonObject> для сортировки
    QList<QJsonObject> correctList;
    for (const QJsonValue &val : correctArray) {
        correctList.append(val.toObject());
    }

    // Сортировка по имени в обратном алфавитном порядке
    std::sort(correctList.begin(), correctList.end(),
              [](const QJsonObject &a, const QJsonObject &b) {
                  QString nameA = a.value("имя").toString();
                  QString nameB = b.value("имя").toString();
                  // Обратный порядок: от Я до А
                  return nameA.localeAwareCompare(nameB) > 0;
              });

    // Собираем обратно в QJsonArray
    QJsonArray sortedCorrect;
    for (const QJsonObject &obj : correctList) {
        sortedCorrect.append(obj);
    }

    // Заполняем таблицы
    ui->correctTable->setRowCount(0);
    ui->errorTable->setRowCount(0);
    fillTable(ui->correctTable, sortedCorrect);
    fillTable(ui->errorTable, brokenArray);

    // Перезаписываем исходный JSON только корректными объектами
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось записать обновлённый файл");
        return;
    }
    file.write(QJsonDocument(sortedCorrect).toJson());
    file.close();

    // Сохраняем битые объекты в broken.json
    if (!brokenArray.isEmpty()) {
        QFileInfo originalInfo(jsonFile);
        QString brokenPath = originalInfo.absolutePath() + "/broken.json";
        QFile brokenFile(brokenPath);
        if (brokenFile.open(QIODevice::WriteOnly)) {
            brokenFile.write(QJsonDocument(brokenArray).toJson());
            brokenFile.close();
        }
    }
}

bool MainWindow::isValidObject(const QJsonObject &obj)
{
    QStringList required = {"имя", "фамилия", "рост", "вес"};
    for (const QString &key : required) {
        if (!obj.contains(key))
            return false;
        if (obj.value(key).isString() && obj.value(key).toString().trimmed().isEmpty())
            return false;
    }

    bool ok;
    double height = obj.value("рост").toString().toDouble(&ok);
    if (!ok || height <= 0)
        return false;
    double weight = obj.value("вес").toString().toDouble(&ok);
    if (!ok || weight <= 0)
        return false;

    return true;
}

void MainWindow::fillTable(QTableWidget *table, const QJsonArray &array)
{
    for (const QJsonValue &val : array) {
        QJsonObject obj = val.toObject();
        int row = table->rowCount();
        table->insertRow(row);

        table->setItem(row, 0, new QTableWidgetItem(obj.value("имя").toString()));
        table->setItem(row, 1, new QTableWidgetItem(obj.value("фамилия").toString()));
        table->setItem(row, 2, new QTableWidgetItem(obj.value("рост").toString()));
        table->setItem(row, 3, new QTableWidgetItem(obj.value("вес").toString()));
    }
}
