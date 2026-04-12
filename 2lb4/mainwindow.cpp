#include "mainwindow.hpp"
#include "product.hpp"
#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    // Группа "Товары"
    QGroupBox *groupBox = new QGroupBox("Товары");
    QFormLayout *formLayout = new QFormLayout;

    // Поля ввода
    lineEditCargo = new QLineEdit;
    formLayout->addRow("Груз:", lineEditCargo);

    lineEditCountry = new QLineEdit;
    formLayout->addRow("Страна:", lineEditCountry);

    lineEditWeight = new QLineEdit;
    formLayout->addRow("Вес:", lineEditWeight);

    lineEditPrice = new QLineEdit;
    formLayout->addRow("Цена:", lineEditPrice);

    // Способ доставки (радиокнопки)
    QHBoxLayout *deliveryLayout = new QHBoxLayout;
    radioPlane = new QRadioButton("Самолет");
    radioShip = new QRadioButton("Корабль");
    deliveryLayout->addWidget(radioPlane);
    deliveryLayout->addWidget(radioShip);
    formLayout->addRow("Способ доставки:", deliveryLayout);

    // Маркеры (чекбоксы)
    QVBoxLayout *markersLayout = new QVBoxLayout;
    checkDamage = new QCheckBox("Повреждение");
    checkNew = new QCheckBox("Новинка");
    checkIrrevocable = new QCheckBox("Безвозвратное");
    markersLayout->addWidget(checkDamage);
    markersLayout->addWidget(checkNew);
    markersLayout->addWidget(checkIrrevocable);
    formLayout->addRow("Маркеры:", markersLayout);

    groupBox->setLayout(formLayout);

    // Кнопки
    QPushButton *buttonReset = new QPushButton("Сброс");
    QPushButton *buttonSave = new QPushButton("Сохранить");
    buttonReset->setStyleSheet("background-color: red; color: white;");
    buttonSave->setStyleSheet("background-color: green; color: white;");
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(buttonReset);
    buttonLayout->addWidget(buttonSave);

    // Основной layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    // Подключение сигналов
    connect(buttonReset, &QPushButton::clicked, this, &MainWindow::resetForm);
    connect(buttonSave, &QPushButton::clicked, this, &MainWindow::saveForm);
}

void MainWindow::resetForm() {
    lineEditCargo->clear();
    lineEditCountry->clear();
    lineEditWeight->clear();
    lineEditPrice->clear();
    radioPlane->setChecked(false);
    radioShip->setChecked(false);
    checkDamage->setChecked(false);
    checkNew->setChecked(false);
    checkIrrevocable->setChecked(false);
}

void MainWindow::saveForm() {
    // 1. Груз: англ/рус, только первая буква заглавная
    QString cargo = lineEditCargo->text().trimmed();
    QRegularExpression cargoRegex("^[A-ZА-Я][a-zа-я]*$");
    if (!cargoRegex.match(cargo).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Груз: только буквы (англ/рус), первая буква заглавная.");
        return;
    }

    // 2. Страна: англ/рус, первая заглавная + остальные строчные ИЛИ все заглавные
    QString country = lineEditCountry->text().trimmed();
    QRegularExpression countryRegex("^([A-ZА-Я][a-zа-я]*|[A-ZА-Я]+)$");
    if (!countryRegex.match(country).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Страна: только буквы (англ/рус), либо первая заглавная, либо все заглавные.");
        return;
    }

    // 3. Вес: целое положительное число
    bool okWeight;
    int weight = lineEditWeight->text().trimmed().toInt(&okWeight);
    if (!okWeight || weight <= 0) {
        QMessageBox::warning(this, "Ошибка", "Вес: целое положительное число (кг).");
        return;
    }

    // 4. Цена: положительное число, при пересчёте в руб/кг не более 100000
    bool okPrice;
    double price = lineEditPrice->text().trimmed().toDouble(&okPrice);
    if (!okPrice || price <= 0) {
        QMessageBox::warning(this, "Ошибка", "Цена: положительное число.");
        return;
    }
    if (price / weight > 100000.0) {
        QMessageBox::warning(this, "Ошибка", "Цена: стоимость за кг превышает 100 000 руб/кг.");
        return;
    }

    // 5. Способ доставки: обязательно выбран
    QString deliveryMethod;
    if (radioPlane->isChecked())
        deliveryMethod = "Самолет";
    else if (radioShip->isChecked())
        deliveryMethod = "Корабль";
    else {
        QMessageBox::warning(this, "Ошибка", "Выберите способ доставки.");
        return;
    }

    // 6. Маркеры (необязательные)
    QList<QString> markers;
    if (checkDamage->isChecked()) markers << "Повреждение";
    if (checkNew->isChecked()) markers << "Новинка";
    if (checkIrrevocable->isChecked()) markers << "Безвозвратное";

    // Создание объекта и сохранение в файл
    Product product(cargo, country, weight, price, deliveryMethod, markers);
    if (product.saveToFile("result.txt")) {
        QMessageBox::information(this, "Успех", "Данные сохранены в result.txt");
        resetForm(); // опционально: очистить форму после сохранения
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось записать файл.");
    }
}
