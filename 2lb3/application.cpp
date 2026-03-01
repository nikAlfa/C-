#include "application.hpp"
#include <iostream>

using namespace std;

// Конструктор
Application::Application(const string& fName, const string& lName,
                         ApplicationType t, const string& comm, int d)
    : firstName(fName), lastName(lName), type(t), comment(comm), data(d) {}

void Application::display() const {
    cout << "\n=== Заявление ===" << endl;
    cout << "Студент: " << firstName << " " << lastName << endl;
    cout << "Тип: ";
    switch (type) {
        case ApplicationType::Promotion:
            cout << "Перевод на следующий курс";
            break;
        case ApplicationType::GroupTransfer:
            cout << "Перевод в другую группу";
            break;
    }
    cout << endl;
    cout << "Комментарий: " << (comment.empty() ? "нет" : comment) << endl;
    cout << "Данные: " << data << endl;
}
