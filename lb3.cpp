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
    bool negative = false;

    for (int i = 0; i < N; i++) {
        int num;
        cout << "Введите число " << i + 1 << ": ";
        cin >> num;

        if (num < 0) {
            negative = true;
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

    if (negative) {
        cout << "Сумма отрицательных чисел равна: " << sum << endl;
        cout << "Наибольшее отрицаьельное число: " << max << endl;
        cout << "Количество его повторений: " << count << endl;
    }
    else {
        cout << "В последовательности нет отрицательных чисел!" << endl;
    }

    //2

    float x;

    do {
        cout << "Введите число x(|x| < 1.000): " << endl;
        cin >> x;

        if (fabs(x) >= 1.000) {
            cout << "Число не соответствует условию!" << endl;
        }
    } while (fabs(x) >= 1.000);

    int _maxX = 0;
    int fog = abs(x * 1000);
    if (fog == 0) {
        _maxX = 0;
    }
    while (fog > 0) {
        int digit = fog % 10;
        if (digit > _maxX) {
            _maxX = digit;
        }
        fog /= 10;
    }

    cout << "Наибольшая цифра числа x: " << _maxX << endl;
}
