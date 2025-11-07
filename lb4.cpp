#include <iostream>
#include <cmath>

using namespace std;
int num1, num2, num3;
int countMaxDigit(int number) {
    cout << "исп. функция подсчета максимальной цифры" << endl;

    number = abs(number);
    if (number == 0) return 1; 

    int maxDigit = 0;
    int temp = number;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        temp /= 10;
    }


    int count = 0;
    temp = number;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit == maxDigit) {
            count++;
        }
        temp /= 10;
    }

    return count;
}

double averageOfThree(int a, int b, int c) {
    cout << "исп. функция среднего по модулю трех чисел" << endl;

    double sum = abs(a) + abs(b) + abs(c);
    return sum / 3.0;
}

int task1() {
    cout << "исп. функция пункта 1" << endl;
    cout << "Введите три числа: ";
    cin >> num1 >> num2 >> num3;

    int count = 0;
    if (num1 != 0) count++;
    if (num2 != 0) count++;
    if (num3 != 0) count++;

    cout << "Количество чисел: " << count << endl;

    int result;
    int number;
    if (count == 1) {
        if (num1 > 0) {
            number = num1;
            result = countMaxDigit(number);
        }
        else if (num2 > 0) {
            number = num2;
            result = countMaxDigit(number);
        }
        else {
            number = num3;
            result = countMaxDigit(number);
        }
        cout << "Количество повторений максимальной цифры: " << result << endl;      
    }
    else if (count == 3) {
        result = averageOfThree(num1, num2, num3);
        cout << "Среднее по модулю: " << result << endl;
    }
    else {
        cout << "Ошибка: должно быть либо 1, либо 3 числа!" << endl;
        result = 0;
    }

    return result;
}

void task2(int num1, int num2, int num3) {
    cout << "исп. функция пункта 2" << endl;

    int count = 0;
    if (num1 != 0) count++;
    if (num2 != 0) count++;
    if (num3 != 0) count++;

    cout << "Количество чисел: " << count << endl;

    int result;
    int number;
    if (count == 1) {
        if (num1 > 0) {
            number = num1;
            result = countMaxDigit(number);
        }
        else if (num2 > 0) {
            number = num2;
            result = countMaxDigit(number);
        }
        else {
            number = num3;
            result = countMaxDigit(number);
        }
        cout << "Количество повторений максимальной цифры: " << result << endl;
    }
    else if (count == 3) {
        double result = averageOfThree(num1, num2, num3);
        if (num1 != num2 != num3) {
            cout << "Среднее по модулю: " << result << endl;
        }
        else {
            int arr[] = { num1 , num2 , num3 };
            int i = 1;
            int min = arr[0];
            int iMin = 0;
            while (i < 3) {
                if (arr[i] < min) {
                    min = arr[i];
                    iMin = i;
                }
                i++;
            }
            cout << "Минимальное значаение: " << min << endl;
        }
        
    }
    else {
        cout << "Ошибка: должно быть либо 1, либо 3 числа!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        cout << "1 - Пункт 1 (функция возвращает значение)" << endl;
        cout << "2 - Пункт 2 (void функция)" << endl;
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int result = task1();
            cout << "Результат функции: " << result << endl;
            break;
        }
        case 2: {
            int a, b, c;
            cout << "Введите три числа: ";
            cin >> a >> b >> c;
            task2(a, b, c);
            break;
        }
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
