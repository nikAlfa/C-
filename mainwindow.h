#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_loadPhotoButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::MainWindow *ui;
    QString selectedPhotoPath;
    bool isPhotoLoaded;

    bool validateInputs();
    bool isNicknameUnique(const QString &nickname);
    void saveAccount();
    QString encryptPassword(const QString &password);
};

#endif // MAINWINDOW_H
