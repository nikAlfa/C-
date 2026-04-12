#include "date.hpp"

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

QString Date::toString() const {
    return QString("%1.%2.%3")
    .arg(day, 2, 10, QChar('0'))
        .arg(month, 2, 10, QChar('0'))
        .arg(year, 4, 10);
}
