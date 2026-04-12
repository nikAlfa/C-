#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "passwindow.hpp"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Пропуска - Лабораторная 5");

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"ФИО", "Дата рождения"});
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loadButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл с данными", "",
                                                    "Text files (*.txt);;All files (*.*)");
    if (!fileName.isEmpty())
        loadFromFile(fileName);
}

void MainWindow::loadFromFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
        return;
    }

    persons.clear();
    QTextStream in(&file);
    int lineNum = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        lineNum++;

        QStringList parts = line.split(' ', Qt::SkipEmptyParts);
        if (parts.size() < 7) {
            QMessageBox::warning(this, "Ошибка",
                                 QString("Строка %1: недостаточно полей.").arg(lineNum));
            continue;
        }

        bool ok;
        int code = parts[0].toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Ошибка",
                                 QString("Строка %1: неверный код.").arg(lineNum));
            continue;
        }

        try {
            if (code == 1) { // RuP: код, Ф, И, О, д, м, г
                if (parts.size() < 7) throw std::runtime_error("Недостаточно полей для RuP");
                QString lastName = parts[1];
                QString firstName = parts[2];
                QString patronymic = parts[3];
                int day = parts[4].toInt(&ok);
                if(!ok) throw std::runtime_error("День не число");
                int month = parts[5].toInt(&ok);
                if(!ok) throw std::runtime_error("Месяц не число");
                int year = parts[6].toInt(&ok);
                if(!ok) throw std::runtime_error("Год не число");
                Date date(day, month, year);
                persons.push_back(std::make_unique<RuP>(lastName, firstName, patronymic, date));
            }
            else if (code == 2) { // AmP: код, И, И2, Ф, м, д, г
                if (parts.size() < 7) throw std::runtime_error("Недостаточно полей для AmP");
                QString firstName = parts[1];
                QString middleName = parts[2];
                QString lastName = parts[3];
                int month = parts[4].toInt(&ok);
                if(!ok) throw std::runtime_error("Месяц не число");
                int day = parts[5].toInt(&ok);
                if(!ok) throw std::runtime_error("День не число");
                int year = parts[6].toInt(&ok);
                if(!ok) throw std::runtime_error("Год не число");
                Date date(day, month, year);
                persons.push_back(std::make_unique<AmP>(firstName, middleName, lastName, date));
            }
            else {
                throw std::runtime_error("Неизвестный код записи");
            }
        }
        catch (const std::exception& e) {
            QMessageBox::warning(this, "Ошибка",
                                 QString("Строка %1: %2").arg(lineNum).arg(e.what()));
        }
    }

    updateTable();
}

void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(static_cast<int>(persons.size()));
    for (size_t i = 0; i < persons.size(); ++i) {
        ui->tableWidget->setItem(static_cast<int>(i), 0,
                                 new QTableWidgetItem(persons[i]->getDisplayName()));
        ui->tableWidget->setItem(static_cast<int>(i), 1,
                                 new QTableWidgetItem(persons[i]->getBirthDate().toString()));
    }
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column) {
    Q_UNUSED(column)
    if (row < 0 || row >= static_cast<int>(persons.size()))
        return;
    persons[row]->craft(this, row);
}

void MainWindow::onPersonRemoved() {
    PassWindow* pass = qobject_cast<PassWindow*>(sender());
    if (pass) {
        int idx = pass->getPersonIndex();
        removePerson(idx);
    }
}

void MainWindow::removePerson(int index) {
    if (index < 0 || index >= static_cast<int>(persons.size()))
        return;
    persons.erase(persons.begin() + index);
    updateTable();
}
