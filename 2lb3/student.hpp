#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <memory> // для умных указателей

using namespace std;

// Предварительное объявление структуры Application
struct Application;

class Student {
private:
    string firstName;
    string lastName;
    vector<string> debts; // список долгов (предметы)
    string studentID;           // ID студента

    // Новые поля согласно варианту
    string major;      // направление
    int course;             // номер курса
    int group;              // номер группы
    int variant;            // номер варианта

public:
    // Конструкторы
    Student();
    Student(const string& fName, const string& lName,
            const vector<string>& debtsList = {},
            const string& id = "",
            const string& major = "",
            int course = 1,
            int group = 1,
            int variant = 1);

    // Конструктор копирования
    Student(const Student& other);

    // Оператор присваивания
    Student& operator=(const Student& other);

    // Деструктор
    ~Student();

    // Ранее реализованные операторы
    Student operator+(const Student& other) const;  // объединение
    Student& operator-=(const Student& other);      // вычитание долгов
    Student operator/(const Student& other) const;  // пересечение долгов

    // Геттеры для старых полей
    string getFirstName() const;
    string getLastName() const;
    vector<string> getDebts() const;
    string getStudentID() const;

    // Сеттеры для старых полей
    void setFirstName(const string& name);
    void setLastName(const string& surname);
    void setDebts(const vector<string>& debtsList);
    void addDebt(const string& subject);
    void removeDebt(const string& subject);
    void setStudentID(const string& id);

    // Геттеры для новых полей
    string getMajor() const;
    int getCourse() const;
    int getGroup() const;
    int getVariant() const;

    // Сеттеры для новых полей
    void setMajor(const string& newMajor);
    void setCourse(int newCourse);
    void setGroup(int newGroup);
    void setVariant(int newVariant);

    // Метод вывода информации
    void displayInfo() const;

    // Новые методы для создания заявлений
    Application createPromotionApplication(const string& comment = "");
    Application createGroupTransferApplication(int newGroup, const string& comment = "");

private:
    // Вспомогательные методы для работы с долгами
    vector<string> mergeDebts(const vector<string>& debts1,
                                         const vector<string>& debts2) const;
    vector<string> subtractDebts(const vector<string>& debts1,
                                          const vector<string>& debts2) const;
    vector<string> intersectDebts(const vector<string>& debts1,
                                           const vector<string>& debts2) const;
};
