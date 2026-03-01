#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::vector<std::string> debts; // вектор долгов (предметы)

protected:
    std::string studentID;

public:
    // Конструкторы
    Student();
    Student(const std::string& fName, const std::string& lName, 
            const std::vector<std::string>& debtsList = {}, 
            const std::string& id = "");
    
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
    std::string getFirstName() const;
    std::string getLastName() const;
    std::vector<std::string> getDebts() const;
    std::string getStudentID() const;

    // Сеттеры
    void setFirstName(const std::string& name);
    void setLastName(const std::string& surname);
    void setDebts(const std::vector<std::string>& debtsList);
    void addDebt(const std::string& subject);  // добавить долг
    void removeDebt(const std::string& subject); // удалить долг
    void setStudentID(const std::string& id);

    // Метод вывода информации
    void displayInfo() const;

private:
    // Вспомогательные методы для работы с долгами
    std::vector<std::string> mergeDebts(const std::vector<std::string>& debts1, 
                                        const std::vector<std::string>& debts2) const;
    std::vector<std::string> subtractDebts(const std::vector<std::string>& debts1, 
                                          const std::vector<std::string>& debts2) const;
    std::vector<std::string> intersectDebts(const std::vector<std::string>& debts1, 
                                           const std::vector<std::string>& debts2) const;
};
