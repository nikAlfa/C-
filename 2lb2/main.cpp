#include <iostream>
#include "student.hpp"

using namespace std;

int main() {
    // Создание студентов с долгами
    cout << "\n=== Создание студентов ===" << endl;
    
    vector<string> debts1 = {"Математика", "Физика", "Программирование"};
    Student student1("Иван", "Иванов", debts1, "А123БВ");
    
    vector<string> debts2 = {"Физика", "Химия", "Английский язык"};
    Student student2("Петр", "Петров", debts2, "В456ГД");
    
    student1.displayInfo();
    student2.displayInfo();
    
    // Тестирование оператора +
    cout << "\n=== Тестирование оператора + ===" << endl;
    Student student3 = student1 + student2;
    student3.displayInfo();
    
    // Тестирование оператора / (пересечение)
    cout << "\n=== Тестирование оператора / (пересечение долгов) ===" << endl;
    Student student4 = student1 / student2;
    student4.displayInfo();
    
    // Тестирование оператора -=
    cout << "\n=== Тестирование оператора -= (вычитание долгов) ===" << endl;
    Student student5 = student1; // Копия студента1
    student5 -= student2;
    student5.displayInfo();
    
    // Тестирование добавления и удаления долгов
    cout << "\n=== Тестирование методов работы с долгами ===" << endl;
    student1.addDebt("История");
    student1.addDebt("Физика"); // Попытка добавить существующий долг
    student1.displayInfo();
    
    student1.removeDebt("Математика");
    student1.removeDebt("Биология"); // Попытка удалить несуществующий долг
    student1.displayInfo();
    
    // Тестирование конструктора копирования
    cout << "\n=== Тестирование конструктора копирования ===" << endl;
    Student student6 = student2;
    student6.displayInfo();
    
    // Тестирование оператора присваивания
    cout << "\n=== Тестирование оператора присваивания ===" << endl;
    Student student7;
    student7 = student1;
    student7.displayInfo();
    
    return 0;
}
