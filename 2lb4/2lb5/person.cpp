#include "person.hpp"
#include "passwindow.hpp"
#include "mainwindow.hpp"

// --------------------- RuP ---------------------
RuP::RuP(const QString& last, const QString& first, const QString& patr, const Date& date)
    : lastName(last), firstName(first), patronymic(patr), birthDate(date) {}

QString RuP::getDisplayName() const {
    QString result = lastName + " " + firstName;
    if (!patronymic.isEmpty() && patronymic != "-")
        result += " " + patronymic;
    return result;
}

Date RuP::getBirthDate() const {
    return birthDate;
}

void RuP::craft(QWidget* parent, int index) const {
    PassWindow* pass = new PassWindow(parent);
    pass->setAttribute(Qt::WA_DeleteOnClose);
    pass->setInfo(lastName, firstName, patronymic, birthDate);
    pass->setPersonIndex(index);
    QObject::connect(pass, &PassWindow::personRemoved,
                     qobject_cast<MainWindow*>(parent), &MainWindow::onPersonRemoved);
    pass->show();
}

// --------------------- AmP ---------------------
AmP::AmP(const QString& first, const QString& middle, const QString& last, const Date& date)
    : firstName(first), middleName(middle), lastName(last), birthDate(date) {}

QString AmP::getDisplayName() const {
    return firstName + " " + middleName + " " + lastName;
}

Date AmP::getBirthDate() const {
    return birthDate;
}

void AmP::craft(QWidget* parent, int index) const {
    PassWindow* pass = new PassWindow(parent);
    pass->setAttribute(Qt::WA_DeleteOnClose);
    pass->setInfo(firstName, middleName, lastName, birthDate);
    pass->setPersonIndex(index);
    QObject::connect(pass, &PassWindow::personRemoved,
                     qobject_cast<MainWindow*>(parent), &MainWindow::onPersonRemoved);
    pass->show();
}
