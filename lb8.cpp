#include <iostream>
#include <string>

using namespace std;

struct MagicCalendar {
    string name_season;
    string month_a;
    string month_b;
    string month_c;
    string next_season;

    void change(struct MagicCalendar& season2) {
        string a = month_a;
        month_a = season2.month_b;
        season2.month_b = a;
    }

    void print() {
        cout << month_a << endl;
        cout << month_b << endl;
        cout << month_c << endl;
    }

};

//Сделал на случай, если я не правильно понял задание
//void change(struct MagicCalendar& season1, struct MagicCalendar& season2) {
//    string a = season1.month_a;
//    season1.month_a = season2.month_b;
//    season2.month_b = a;
//}

//void print(struct MagicCalendar& season1, struct MagicCalendar& season2, struct MagicCalendar& season3, struct MagicCalendar& season4) {
//    cout << season1.month_a << endl;
//    cout << season1.month_b << endl;
//    cout << season1.month_c << endl;
//    cout << season2.month_a << endl;
//    cout << season2.month_b << endl;
//    cout << season2.month_c << endl;
//    cout << season3.month_a << endl;
//    cout << season3.month_b << endl;
//    cout << season3.month_c << endl;
//    cout << season4.month_a << endl;
//    cout << season4.month_b << endl;
//    cout << season4.month_c << endl;
//}

int main() {
    setlocale(LC_ALL, "Ru");
    MagicCalendar winter;
    winter.name_season = "Зима";
    winter.month_a = "Декабрь";
    winter.month_b = "Январь";
    winter.month_c = "Февраль";
    winter.next_season = "Весна";
    MagicCalendar spring;
    spring.name_season = "Весна";
    spring.month_a = "Март";
    spring.month_b = "Апрель";
    spring.month_c = "Май";
    spring.next_season = "Лето";
    MagicCalendar summer;
    summer.name_season = "Лето";
    summer.month_a = "Июнь";
    summer.month_b = "Июль";
    summer.month_c = "Август";
    summer.next_season = "Осень";
    MagicCalendar autumn;
    autumn.name_season = "Осень";
    autumn.month_a = "Сентябрь";
    autumn.month_b = "Октябрь";
    autumn.month_c = "Ноябрь";
    autumn.next_season = "Зима";


    while (true) {
        int choice_target;
        cout << "Введите номер функции: ";
        cin >> choice_target;
        switch (choice_target) {
        case 1:
            winter.change(spring);
            spring.change(summer);
            summer.change(autumn);
            autumn.change(winter);
            //change(winter, spring);
            //change(spring, summer);
            //change(summer, autumn);
            //change(autumn, winter);
            break;
        case 2:
            winter.print();
            spring.print();
            summer.print();
            autumn.print();
            //print(winter, spring, summer, autumn)
            break;
        }

    }

    return 0;
}
