#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_loadTxtButton_clicked();
    void on_okButton_clicked();

private:
    Ui::MainWindow *ui;
    void appendToJsonFile(const QString &fileName,
                          const QString &name,
                          const QString &surname,
                          const QString &heightStr,
                          const QString &weightStr);
};

#endif // MAINWINDOW_H
