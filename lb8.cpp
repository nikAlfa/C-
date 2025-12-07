#include <iostream>
#include <string>

using namespace std;

struct MagicCalendar {
    string name_season;
    string month_a;
    string month_b;
    string month_c;
    string next_season;
    MagicCalendar* season2;


    void change() {
        string a = month_a;
        month_a = season2->month_b;
        season2->month_b = a;
    }

    void print() {
        cout << month_a << endl;
        cout << month_b << endl;
        cout << month_c << endl;
    }

};

int main() {
    setlocale(LC_ALL, "Ru");
    MagicCalendar winter;
    winter.name_season = "Зима";
    winter.month_a = "Декабрь";
    winter.month_b = "Январь";
    winter.month_c = "Февраль";
    winter.next_season = "Весна";
    winter.season2 = nullptr;
    MagicCalendar spring;
    spring.name_season = "Весна";
    spring.month_a = "Март";
    spring.month_b = "Апрель";
    spring.month_c = "Май";
    spring.next_season = "Лето";
    spring.season2 = nullptr;
    MagicCalendar summer;
    summer.name_season = "Лето";
    summer.month_a = "Июнь";
    summer.month_b = "Июль";
    summer.month_c = "Август";
    summer.next_season = "Осень";
    summer.season2 = nullptr;
    MagicCalendar autumn;
    autumn.name_season = "Осень";
    autumn.month_a = "Сентябрь";
    autumn.month_b = "Октябрь";
    autumn.month_c = "Ноябрь";
    autumn.next_season = "Зима";
    autumn.season2 = nullptr;

    winter.season2 = &spring;
    spring.season2 = &summer;
    summer.season2 = &autumn;
    autumn.season2 = &winter;


    while (true) {
        int choice_target;
        cout << "Введите номер функции: ";
        cin >> choice_target;
        switch (choice_target) {
        case 1:
            cout << "Смена месяцев со следующим сезоном" << endl;
            winter.change();
            spring.change();
            summer.change();
            autumn.change();
            break;
        case 2:
            cout << "Вывод всех месяцев" << endl;
            winter.print();
            spring.print();
            summer.print();
            autumn.print();
            break;
        }

    }

    return 0;
}
