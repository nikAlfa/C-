#include "student.hpp"

using namespace std;

// Конструктор по умолчанию
Student::Student() : firstName(""), lastName(""), studentID("") {
    cout << "Конструктор по умолчанию создан" << endl;
}

// Конструктор полного заполнения
Student::Student(const string& fName, const string& lName, 
                 const vector<string>& debtsList, const string& id) 
    : firstName(fName), lastName(lName), debts(debtsList), studentID(id) {
    cout << "Конструктор полного заполнения создан" << endl;
}

// Конструктор копирования
Student::Student(const Student& other) 
    : firstName(other.firstName), 
      lastName(other.lastName), 
      debts(other.debts),
      studentID(other.studentID) {
    cout << "Конструктор копирования создан" << endl;
}

// Оператор присваивания (копирующий)
Student& Student::operator=(const Student& other) {
    cout << "Оператор присваивания вызван" << endl;
    
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        debts = other.debts;
        studentID = other.studentID;
    }
    return *this;
}

// Деструктор
Student::~Student() {
    cout << "Деструктор для студента " << firstName << " " << lastName << " запущен" << endl;
    // Опустошаем вектор для демонстрации работы с динамической памятью
    if (!debts.empty()) {
        cout << "  Очистка долгов (" << debts.size() << " предметов): ";
        for (const auto& debt : debts) {
            cout << debt << " ";
        }
        cout << endl;
        debts.clear(); // Опустошаем вектор
    }
}

// Оператор + (объединение)
Student Student::operator+(const Student& other) const {
    Student result;
    
    // имя = "имя1 и имя2"
    result.firstName = firstName + " и " + other.firstName;
    
    // фамилия = "фамилия1 и фамилия2"
    result.lastName = lastName + " и " + other.lastName;
    
    // долги = список долгов без повторов
    result.debts = mergeDebts(debts, other.debts);
    
    return result;
}

// Оператор -= (вычитание долгов)
Student& Student::operator-=(const Student& other) {
    // имя = "имя1 без имя2"
    firstName = firstName + " без " + other.firstName;
    
    // фамилия = "фамилия1 без фамилия2"
    lastName = lastName + " без " + other.lastName;
    
    // долги = список 1 без долгов из 2
    debts = subtractDebts(debts, other.debts);
    
    return *this;
}

// Оператор / (пересечение долгов)
Student Student::operator/(const Student& other) const {
    Student result;
    
    // имя = "имя1 и имя2"
    result.firstName = firstName + " и " + other.firstName;
    
    // фамилия = "фамилия1 и фамилия2"
    result.lastName = lastName + " и " + other.lastName;
    
    // долги = список общих долгов
    result.debts = intersectDebts(debts, other.debts);
    
    return result;
}

// Вспомогательный метод для объединения долгов без повторов
vector<string> Student::mergeDebts(const vector<string>& debts1, 
                                   const vector<string>& debts2) const {
    vector<string> result = debts1;
    
    for (const auto& debt : debts2) {
        if (find(result.begin(), result.end(), debt) == result.end()) {
            result.push_back(debt);
        }
    }
    
    return result;
}

// Вспомогательный метод для вычитания долгов
vector<string> Student::subtractDebts(const vector<string>& debts1, 
                                      const vector<string>& debts2) const {
    vector<string> result;
    
    for (const auto& debt : debts1) {
        if (find(debts2.begin(), debts2.end(), debt) == debts2.end()) {
            result.push_back(debt);
        }
    }
    
    return result;
}

// Вспомогательный метод для пересечения долгов
vector<string> Student::intersectDebts(const vector<string>& debts1, 
                                       const vector<string>& debts2) const {
    vector<string> result;
    
    for (const auto& debt : debts1) {
        if (find(debts2.begin(), debts2.end(), debt) != debts2.end()) {
            result.push_back(debt);
        }
    }
    
    return result;
}

// Геттеры
string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

vector<string> Student::getDebts() const {
    return debts;
}

string Student::getStudentID() const {
    return studentID;
}

// Сеттеры
void Student::setFirstName(const string& name) {
    if (!name.empty() && all_of(name.begin(), name.end(), [](char c) {
        return isalpha(c) || c == ' ' || c == '-';
    })) {
        firstName = name;
    } else {
        cout << "Ошибка: Некорректное имя" << endl;
    }
}

void Student::setLastName(const string& surname) {
    if (!surname.empty() && all_of(surname.begin(), surname.end(), [](char c) {
        return isalpha(c) || c == ' ' || c == '-';
    })) {
        lastName = surname;
    } else {
        cout << "Ошибка: Некорректная фамилия" << endl;
    }
}

void Student::setDebts(const vector<string>& debtsList) {
    debts = debtsList;
}

void Student::addDebt(const string& subject) {
    if (find(debts.begin(), debts.end(), subject) == debts.end()) {
        debts.push_back(subject);
        cout << "Долг по предмету \"" << subject << "\" добавлен" << endl;
    } else {
        cout << "Долг по предмету \"" << subject << "\" уже существует" << endl;
    }
}

void Student::removeDebt(const string& subject) {
    auto it = find(debts.begin(), debts.end(), subject);
    if (it != debts.end()) {
        debts.erase(it);
        cout << "Долг по предмету \"" << subject << "\" удален" << endl;
    } else {
        cout << "Долг по предмету \"" << subject << "\" не найден" << endl;
    }
}

void Student::setStudentID(const string& id) {
    regex idPattern(R"(^[А-ЯA-Z]\d{3}[А-ЯA-Z]{2}$)");
    if (regex_match(id, idPattern)) {
        studentID = id;
    } else {
        cout << "Ошибка: Некорректный ID. Формат: А555АА" << endl;
    }
}

void Student::displayInfo() const {
    cout << "\n=== Информация о студенте ===" << endl;
    cout << "Имя: " << firstName << endl;
    cout << "Фамилия: " << lastName << endl;
    cout << "ID студента: " << (studentID.empty() ? "не указан" : studentID) << endl;
    
    cout << "Долги по предметам: ";
    if (debts.empty()) {
        cout << "нет долгов";
    } else {
        for (size_t i = 0; i < debts.size(); ++i) {
            cout << debts[i];
            if (i < debts.size() - 1) cout << ", ";
        }
    }
    cout << endl;
}
