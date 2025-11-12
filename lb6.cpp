#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int ROWS = 2;
const int COLS = 2;

void print_matrix(int** matrix, int rows, int cols) {
    cout << "\nПолученная матрица " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** get_new_matrix(int matrix[ROWS][COLS]) {
    int rows = matrix[0][0] + ROWS;
    int columns = matrix[0][1] + COLS;

    int** new_matrix = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; ++i) {
        new_matrix[i] = (int*)calloc(columns, sizeof(int));
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i < 2 && j < 2) {
                new_matrix[i][j] = matrix[i][j];
            }
            else {
                new_matrix[i][j] = ((i - 1) * matrix[1][0]) + ((j - 1) * matrix[1][1]);
            }
        }
    }
    return new_matrix;
}

int* findZeroRows(int** matrix, int rows, int cols, int& count) {
    count = 0;

    for (int i = 0; i < rows; i++) {
        bool hasZero = false;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            count++;
        }
    }

    int* arr_index_zero = (int*)malloc(count * sizeof(int));

    int index = 0;
    for (int i = 0; i < rows; i++) {
        bool hasZero = false;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            arr_index_zero[index++] = i;
        }
    }

    return arr_index_zero;
}

int** removeRows(int** matrix, int rows, int cols, int* rowsToRemove, int removeCount, int& newRows) {
    newRows = rows - removeCount;

    if (newRows <= 0) {
        return nullptr;
    }

    int** new_matrix = (int**)malloc(newRows * sizeof(int*));

    for (int i = 0; i < newRows; ++i) {
        new_matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    int new_i = 0;
    for (int i = 0; i < rows; i++) {
        bool shouldRemove = false;
        for (int k = 0; k < removeCount; k++) {
            if (i == rowsToRemove[k]) {
                shouldRemove = true;
                break;
            }
        }

        if (!shouldRemove) {
            for (int j = 0; j < cols; j++) {
                new_matrix[new_i][j] = matrix[i][j];
            }
            new_i++;
        }
    }

    return new_matrix;
}

void freeMatrix(int** matrix, int rows) {
    if (matrix == nullptr) return;

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    setlocale(LC_ALL, "Ru");
    // Первый пункт
    int matrix[ROWS][COLS];
    cout << "Введите элементы матрицы " << ROWS << "x" << COLS << ":" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int rows = matrix[0][0] + ROWS;
    int columns = matrix[0][1] + COLS;

    int** new_matrix = get_new_matrix(matrix);
    //print_matrix(new_matrix, rows, columns);

    int count;
    int* arr_index_zero = findZeroRows(new_matrix, rows, columns, count);


    int newRows;
    int** final_matrix = removeRows(new_matrix, rows, columns, arr_index_zero, count, newRows);

    if (final_matrix != nullptr) {
        cout << "\nМатрица после удаления строк с нулями:";
        print_matrix(final_matrix, newRows, columns);

        freeMatrix(final_matrix, newRows);
    }
    else {
        cout << "\nВсе строки были удалены!" << endl;
    }

    freeMatrix(new_matrix, rows);
    free(arr_index_zero);


    // Второй пункт
    double* a = new double;
    double* b = new double;
    cout << "Введите значение a: ";
    cin >> *a;
    cout << "Введите значение b: ";
    cin >> *b;
    *a = *a * 3;
    double c = *a;
    *a = *b;
    *b = c;
    cout << "Значение переменной a: " << *a << endl;
    cout << "Значение переменной b: " << *b << endl;
    delete a;
    delete b;

    return 0;

}
