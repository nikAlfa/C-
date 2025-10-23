#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    // Первое задание
    int arr[4];
    cout << "Введите последовательно все элементы массива: " << endl;
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    int first = arr[0];
    int last = arr[3];
    int minfirst = 9, minlast = 9;
    
    // Получение минимальной цифры у первого и последнего числа
    while (first > 0) {
        int digit = first % 10;
        if (digit < minfirst) {
            minfirst = digit;
        }
        first /= 10;
    }
    while (last > 0) {
        int digit = last % 10;
        if (digit < minlast) {
            minlast = digit;
        }
        last /= 10;
    }
    
    if (minfirst == minlast) {
        for (int i = 1; i < 4; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
    else {
        cout << "Минимальная цифра первого числа не совпадает с минимальной цифрой последнего числа!" << endl;
    }

    for (int i = 0; i < 4; ++i) cout << arr[i] << ' ';


    // Второе задание

    const int ROWS = 3;
    const int COLS = 4;
    int matrix[ROWS][COLS];

    cout << "Введите элементы матрицы " << ROWS << "x" << COLS << ":" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int sumrow1 = 0, sumrow2 = 0, sumrow3 = 0;

    // Считаем сумму для каждой строки
    for (int j = 0; j < 4; j++) {
        sumrow1 += matrix[0][j];
    }
    sumrow1 = abs(sumrow1);

    for (int j = 0; j < 4; j++) {
        sumrow2 += matrix[1][j];
    }
    sumrow2 = abs(sumrow2);

    for (int j = 0; j < 4; j++) {
        sumrow3 += matrix[2][j];
    }
    sumrow3 = abs(sumrow3);

    cout << "Абсолютные суммы строк:" << endl;
    cout << sumrow1 << endl;
    cout << sumrow2 << endl;
    cout << sumrow3 << endl;

    int minsum = sumrow1;
    int minrowindex = 0;

    if (sumrow2 < minsum) {
        minsum = sumrow2;
        minrowindex = 1;
    }
    if (sumrow3 < minsum) {
        minsum = sumrow3;
        minrowindex = 2;
    }
    cout << "Минимальная сумма: " << minsum << endl;

    for (int j = 0; j < 4; j++) {
        matrix[minrowindex][j] = 0;
    }
    cout << "Матрица после замены:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;

}