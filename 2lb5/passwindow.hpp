#pragma once
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "date.hpp"

class PassWindow : public QDialog {
    Q_OBJECT

public:
    explicit PassWindow(QWidget *parent = nullptr);

    void setInfo(const QString& arg1, const QString& arg2, const QString& arg3, const Date& birth);
    void setPersonIndex(int idx) { personIndex = idx; }
    int getPersonIndex() const { return personIndex; }

signals:
    void personRemoved();

private slots:
    void onPrint();

private:
    QLabel* photoLabel;
    QLabel* nameLabel;
    QLabel* birthLabel;
    QPushButton* printButton;
    QPushButton* cancelButton;
    int personIndex = -1;
};
