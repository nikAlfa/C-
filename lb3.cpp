#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    int N;

    cout << "Введите количество чисел последовательности: ";
    cin >> N;

    if (N <= 0) {
        cout << "Такой последовательности не существует!";
        return 0;
    }

    int sum = 0;
    int max = numeric_limits<int>::min();
    int count = 0;
    bool even = false;

    for (int i = 0; i < N; i++) {
        int num;
        cout << "Введите число " << i + 1 << ": ";
        cin >> num;

        if (num % 2 == 0) {
            even = true;
            sum += num;

            if (num > max) {
                max = num;
                count = 1;
            }
            else if (num == max) {
                count++;
            }
        }
    }

    if (even) {
        cout << "Сумма четных чисел равна: " << sum << endl;
        cout << "Наибольшее четное число: " << max << endl;
    }
    else {
        cout << "В последовательности нет целых чисел!" << endl;
    }

    //2

    int x;

    do {
        cout << "Введите число x (|x| < 1.000): " << endl;
        cin >> x;

        if (abs(x) >= 1000) {
            cout << "Число не соответствует условию!" << endl;
        }
    } while (abs(x) >= 1000);

    int _maxX = 0;
    int fog = abs(x);
    if (fog == 0) {
        _maxX = 0;
    }
    while (fog > 0) {
        int digit = fog % 10;
        if (digit != 0 && digit != 7) {
            if (digit > _maxX) {
                _maxX = digit;
            }
        }
        fog /= 10;
    }
    if (_maxX != 0) {
        cout << "Наибольшая цифра числа x: " << _maxX << endl;
    }
    else {
        cout << "Ошибка. Хоть одно число должно отличаться от 0 и 7!" << endl;
    }
}
