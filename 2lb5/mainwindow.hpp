#pragma once
#include <QMainWindow>
#include <vector>
#include <memory>
#include "person.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onPersonRemoved();

private slots:
    void on_loadButton_clicked();
    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    std::vector<std::unique_ptr<Person>> persons;

    void loadFromFile(const QString &fileName);
    void updateTable();
    void removePerson(int index);
};
