#pragma once
#include <QString>
#include <QWidget>
#include "date.hpp"

class Person {
public:
    virtual ~Person() = default;
    virtual QString getDisplayName() const = 0;
    virtual Date getBirthDate() const = 0;
    virtual void craft(QWidget* parent, int index) const = 0;
};

class RuP : public Person {
private:
    QString lastName;
    QString firstName;
    QString patronymic;
    Date birthDate;
public:
    RuP(const QString& last, const QString& first, const QString& patr, const Date& date);
    QString getDisplayName() const override;
    Date getBirthDate() const override;
    void craft(QWidget* parent, int index) const override;
};

class AmP : public Person {
private:
    QString firstName;
    QString middleName;
    QString lastName;
    Date birthDate;
public:
    AmP(const QString& first, const QString& middle, const QString& last, const Date& date);
    QString getDisplayName() const override;
    Date getBirthDate() const override;
    void craft(QWidget* parent, int index) const override;
};
