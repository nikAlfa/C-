#pragma once
#include <QString>

struct Date {
    int day;
    int month;
    int year;

    Date(int d = 1, int m = 1, int y = 2000);
    QString toString() const;
};
