#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void resetForm();
    void saveForm();

private:
    QLineEdit *lineEditCargo;
    QLineEdit *lineEditCountry;
    QLineEdit *lineEditWeight;
    QLineEdit *lineEditPrice;
    QRadioButton *radioPlane;
    QRadioButton *radioShip;
    QCheckBox *checkDamage;
    QCheckBox *checkNew;
    QCheckBox *checkIrrevocable;
};
