#include "student.hpp"
#include "application.hpp"
#include <cctype>

using namespace std;

// Конструктор по умолчанию
Student::Student()
    : firstName(""), lastName(""), studentID(""),
      major(""), course(1), group(1), variant(1) {
    cout << "Конструктор по умолчанию Student" << endl;
}

// Конструктор полного заполнения
Student::Student(const string& fName, const string& lName,
                 const vector<string>& debtsList, const string& id,
                 const string& major, int course, int group, int variant)
    : firstName(fName), lastName(lName), debts(debtsList), studentID(id),
      major(major), course(course), group(group), variant(variant) {
    cout << "Конструктор полного заполнения Student" << endl;
}

// Конструктор копирования
Student::Student(const Student& other)
    : firstName(other.firstName), lastName(other.lastName),
      debts(other.debts), studentID(other.studentID),
      major(other.major), course(other.course), group(other.group),
      variant(other.variant) {
    cout << "Конструктор копирования Student" << endl;
}

// Оператор присваивания
Student& Student::operator=(const Student& other) {
    cout << "Оператор присваивания Student" << endl;
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        debts = other.debts;
        studentID = other.studentID;
        major = other.major;
        course = other.course;
        group = other.group;
        variant = other.variant;
    }
    return *this;
}

// Деструктор
Student::~Student() {
    cout << "Деструктор Student для " << firstName << " " << lastName << endl;
    if (!debts.empty()) {
        cout << "  Очистка долгов (" << debts.size() << " предметов)" << endl;
        debts.clear();
    }
}

// Оператор + (объединение)
Student Student::operator+(const Student& other) const {
    Student result;
    result.firstName = firstName + " и " + other.firstName;
    result.lastName = lastName + " и " + other.lastName;
    result.debts = mergeDebts(debts, other.debts);
    return result;
}

// Оператор -= (вычитание долгов)
Student& Student::operator-=(const Student& other) {
    firstName = firstName + " без " + other.firstName;
    lastName = lastName + " без " + other.lastName;
    debts = subtractDebts(debts, other.debts);
    return *this;
}

// Оператор / (пересечение долгов)
Student Student::operator/(const Student& other) const {
    Student result;
    result.firstName = firstName + " и " + other.firstName;
    result.lastName = lastName + " и " + other.lastName;
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

// Геттеры и сеттеры для старых полей
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
vector<string> Student::getDebts() const { return debts; }
string Student::getStudentID() const { return studentID; }

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

// Геттеры для новых полей
string Student::getMajor() const { return major; }
int Student::getCourse() const { return course; }
int Student::getGroup() const { return group; }
int Student::getVariant() const { return variant; }

// Сеттеры для новых полей
void Student::setMajor(const string& newMajor) {
    if (!newMajor.empty()) major = newMajor;
    else cout << "Ошибка: направление не может быть пустым" << endl;
}

void Student::setCourse(int newCourse) {
    if (newCourse >= 1 && newCourse <= 6) course = newCourse;
    else cout << "Ошибка: номер курса должен быть от 1 до 6" << endl;
}

void Student::setGroup(int newGroup) {
    if (newGroup >= 1) group = newGroup;
    else cout << "Ошибка: номер группы должен быть положительным" << endl;
}

void Student::setVariant(int newVariant) {
    if (newVariant >= 1) variant = newVariant;
    else cout << "Ошибка: номер варианта должен быть положительным" << endl;
}

// Метод вывода информации
void Student::displayInfo() const {
    cout << "\n=== Информация о студенте ===" << endl;
    cout << "Имя: " << firstName << endl;
    cout << "Фамилия: " << lastName << endl;
    cout << "ID: " << (studentID.empty() ? "не указан" : studentID) << endl;
    cout << "Направление: " << (major.empty() ? "не указано" : major) << endl;
    cout << "Курс: " << course << endl;
    cout << "Группа: " << group << endl;
    cout << "Вариант: " << variant << endl;
    cout << "Долги: ";
    if (debts.empty()) cout << "нет";
    else {
        for (size_t i = 0; i < debts.size(); ++i) {
            cout << debts[i];
            if (i < debts.size() - 1) cout << ", ";
        }
    }
    cout << endl;
}

// Методы создания заявлений
Application Student::createPromotionApplication(const string& comment) {
    int newCourse = course + 1;
    if (newCourse > 6) {
        cout << "Невозможно перевести на следующий курс: максимальный курс 6" << endl;
        // В реальности можно выбрасывать исключение, но здесь просто вернем заявление с текущим курсом
        newCourse = course;
    }
    return Application(firstName, lastName, ApplicationType::Promotion,
                       comment, newCourse);
}

Application Student::createGroupTransferApplication(int newGroup, const string& comment) {
    return Application(firstName, lastName, ApplicationType::GroupTransfer,
                       comment, newGroup);
}
