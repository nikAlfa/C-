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


int** get_new_matrix(int** matrix) {
    int rows = matrix[0][0] + ROWS;
    int columns = matrix[0][1] + COLS;

    matrix = (int**)realloc(matrix, rows*sizeof(int*));

    for (int i = 0; i < rows; ++i) {
        if (i < 2) {
            matrix[i] = (int*)realloc(matrix[i], columns * sizeof(int));
        }
        else {
            matrix[i] = (int*)malloc(columns * sizeof(int));
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i < 2 && j < 2) {
                matrix[i][j] = matrix[i][j];
            }
            else {
                matrix[i][j] = ((i - 1) * matrix[1][0]) + ((j - 1) * matrix[1][1]);
            }
        }
    }
    return matrix;
}

int* findZeroColumns(int** matrix, int rows, int cols, int& count) {
    count = 0;
    for (int j = 0; j < cols; j++) {
        bool hasZero = false;
        for (int i = 0; i < rows; i++) {
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
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                arr_index_zero[index] = j;
                index++;
                break;
            }
        }
    }

    return arr_index_zero;
}

int** removeRows(int** matrix, int rows, int cols, int* colsToRemove, int removeCount, int& newRows) {
    newRows = rows - removeCount;
    if (newRows <= 0) {
        return nullptr;
    }

    for (int j = 0; j < removeCount; j++) {
        int colToRemove = colsToRemove[j]-j;
        for (int col = colToRemove; col < cols - 1; col++) {
            for (int row = 0; row < rows; row++) {
                matrix[row][col] = matrix[row][col + 1];
            }
        }
    }

    for (int x=0; x < rows; x++) {
        matrix[x] = (int*)realloc(matrix[x], newRows * sizeof(int));
    }

    return matrix;
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
    int** matrix = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; ++i) {
        matrix[i] = (int*)calloc(ROWS, sizeof(int));
    }
    cout << "Введите элементы матрицы " << ROWS << "x" << COLS << ":" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
            if (matrix[i][j] < 0) {
                cout << "Введите числа большие нуля" << endl;
                j -= 1;
            }
        }
    }

    int rows = matrix[0][0] + ROWS;
    int columns = matrix[0][1] + COLS;
    matrix = get_new_matrix(matrix);
    print_matrix(matrix, rows, columns);

    int count;
    int* arr_index_zero = findZeroColumns(matrix, rows, columns, count);


    int newRows;
    matrix = removeRows(matrix, rows, columns, arr_index_zero, count, newRows);

    if (matrix != nullptr) {
        cout << "\nМатрица после удаления строк с нулями:";
        print_matrix(matrix, columns, newRows);

        freeMatrix(matrix, newRows);
    }
    else {
        cout << "\nВсе строки были удалены!" << endl;
    }

    //freeMatrix(final_matrix, rows);
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
