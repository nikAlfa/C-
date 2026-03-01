#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    vector<string> debts; // вектор долгов (предметы)

protected:
    string studentID;

public:
    // Конструкторы
    Student();
    Student(const string& fName, const string& lName, 
            const vector<string>& debtsList = {}, 
            const string& id = "");
    
    // Конструктор копирования
    Student(const Student& other);
    
    // Оператор присваивания (копирующий)
    Student& operator=(const Student& other);
    
    // Деструктор
    ~Student();

    // Операторы согласно варианту
    Student operator+(const Student& other) const;  // объединение
    Student& operator-=(const Student& other);      // вычитание долгов
    Student operator/(const Student& other) const;  // пересечение долгов

    // Геттеры
    string getFirstName() const;
    string getLastName() const;
    vector<string> getDebts() const;
    string getStudentID() const;

    // Сеттеры
    void setFirstName(const string& name);
    void setLastName(const string& surname);
    void setDebts(const vector<string>& debtsList);
    void addDebt(const string& subject);  // добавить долг
    void removeDebt(const string& subject); // удалить долг
    void setStudentID(const string& id);

    // Метод вывода информации
    void displayInfo() const;

private:
    // Вспомогательные методы для работы с долгами
    vector<string> mergeDebts(const vector<string>& debts1, 
                                        const vector<string>& debts2) const;
    vector<string> subtractDebts(const vector<string>& debts1, 
                                          const vector<string>& debts2) const;
    vector<string> intersectDebts(const vector<string>& debts1, 
                                           const vector<string>& debts2) const;
};

