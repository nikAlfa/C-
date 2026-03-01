#pragma once

#include <string>
#include <vector>
#include <memory>
#include "student.hpp"
#include "application.hpp"

using namespace std;

class Deanery {
private:
    string address;
    vector<shared_ptr<Student>> students; // список указателей на студентов

public:
    // Конструктор
    explicit Deanery(const string& addr = "");

    // Запрет копирования
    Deanery(const Deanery&) = delete;
    Deanery& operator=(const Deanery&) = delete;

    // Деструктор (можно оставить по умолчанию, т.к. используем умные указатели)
    ~Deanery() = default;

    // Методы доступа к адресу
    string getAddress() const;
    void setAddress(const string& addr);

    // Метод прикрепления студента
    void attachStudent(shared_ptr<Student> student);

    // Метод исключения студента по ID
    bool detachStudent(const string& studentID);

    // Вывод информации о всех студентах деканата
    void printAllStudents() const;

    // Получить количество студентов
    size_t getStudentCount() const;
};
