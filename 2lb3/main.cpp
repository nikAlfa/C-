#include <iostream>
#include <memory>
#include "student.hpp"
#include "application.hpp"
#include "deanery.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание студентов с новыми полями
    cout << "\n--- Создание студентов ---" << endl;
    auto student1 = make_shared<Student>("Иван", "Иванов",
                                          vector<string>{"Математика", "Физика"},
                                          "A123BC", "Программная инженерия", 2, 3, 5);
    auto student2 = make_shared<Student>("Петр", "Петров",
                                          vector<string>{"Физика", "Химия"},
                                          "B456CD", "Прикладная математика", 3, 2, 7);
    auto student3 = make_shared<Student>("Сидор", "Сидоров",
                                          vector<string>{}, "C789DE",
                                          "Информатика", 1, 1, 1);

    student1->displayInfo();
    student2->displayInfo();
    student3->displayInfo();

    // Создание деканата
    cout << "\n--- Создание деканата ---" << endl;
    Deanery deanery("ул. Ленина, д.1");
    cout << "Деканат создан по адресу: " << deanery.getAddress() << endl;

    // Прикрепление студентов
    cout << "\n--- Прикрепление студентов к деканату ---" << endl;
    deanery.attachStudent(student1);
    deanery.attachStudent(student2);
    deanery.attachStudent(student3);
    deanery.printAllStudents();

    // Создание заявлений
    cout << "\n--- Создание заявлений студентами ---" << endl;
    Application app1 = student1->createPromotionApplication("Успешно сдал сессию");
    Application app2 = student2->createGroupTransferApplication(5, "Хочу в другую группу");

    app1.display();
    app2.display();

    // Исключение студента из деканата
    cout << "\n--- Исключение студента ---" << endl;
    deanery.detachStudent("B456CD"); // исключаем Петрова
    deanery.printAllStudents();

    cout << "Моя оценка: интерес - 8/10, наполненность - 9/10, сложность - 6/10" << endl;
  
    return 0;
}
