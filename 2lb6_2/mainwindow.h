#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    void fillTable(QTableWidget *table, const QJsonArray &array);
    bool isValidObject(const QJsonObject &obj);
};

#endif // MAINWINDOW_H
