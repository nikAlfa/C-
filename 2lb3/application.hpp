#pragma once

#include <string>

using namespace std;

// Тип заявления
enum class ApplicationType {
    Promotion,           // перевод на следующий курс
    GroupTransfer,       // перевод в другую группу
    // можно добавить другие типы
};

struct Application {
    string firstName;      // имя студента
    string lastName;       // фамилия студента
    ApplicationType type;       // тип заявления
    string comment;        // комментарий
    int data;                   // данные (номер курса или группы)

    Application(const string& fName, const string& lName,
                ApplicationType t, const string& comm, int d);

    void display() const;
};
