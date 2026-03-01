#include "deanery.hpp"
#include <algorithm>

using namespace std;

Deanery::Deanery(const string& addr) : address(addr) {}

string Deanery::getAddress() const { return address; }
void Deanery::setAddress(const string& addr) { address = addr; }

void Deanery::attachStudent(shared_ptr<Student> student) {
    if (student) {
        students.push_back(student);
        cout << "Студент " << student->getFirstName() << " " << student->getLastName()
                  << " прикреплен к деканату." << endl;
    }
}

bool Deanery::detachStudent(const string& studentID) {
    auto it = find_if(students.begin(), students.end(),
        [&studentID](const shared_ptr<Student>& s) {
            return s->getStudentID() == studentID;
        });
    if (it != students.end()) {
        cout << "Студент " << (*it)->getFirstName() << " " << (*it)->getLastName()
                  << " исключен из деканата." << endl;
        students.erase(it);
        return true;
    }
    cout << "Студент с ID " << studentID << " не найден." << endl;
    return false;
}

void Deanery::printAllStudents() const {
    cout << "\n=== Деканат по адресу: " << address << " ===" << endl;
    if (students.empty()) {
        cout << "В деканате нет студентов." << endl;
        return;
    }
    cout << "Список студентов (" << students.size() << "):" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "\n--- Студент " << i+1 << " ---";
        students[i]->displayInfo();
    }
}

size_t Deanery::getStudentCount() const { return students.size(); }
