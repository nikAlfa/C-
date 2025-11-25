#include <iostream>
#include <vector>
#include <array>
#include <random>

using namespace std;

void print_vector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << "]";
    cout << endl;
}

// ЗНАЧЕНИЕ. Создает копию массива, не изменяя его в основной функции. Отличается от других тем, что копирует
// полученный массив и работает с ним внутри функции.
void sort_array_value(array<int, 10> arr) {
    for (int i = 1; i < 10; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
}

// ССЫЛКА. Изменяет массив в основной функции, не копируя его. Отличается от передачи значения тем, что не копируя массив,
// изменяет его.
void sort_array_link(array<int, 10>& arr) {
    for (int i = 1; i < 10; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// УКАЗАТЕЛЬ. Точно такой же смысл, как и у ссылки. Отличается от ссылки тем, что обладает явным разыменовыванием.
void sort_array_indicator(array<int, 10>* arr) {
    for (int i = 1; i < 10; ++i) {
        int key = (*arr)[i];
        int j = i - 1;
        while (j >= 0 && (*arr)[j] > key) {
            (*arr)[j + 1] = (*arr)[j];
            --j;
        }
        (*arr)[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    vector<int> vec = { 1, 2, 3, 4 };

    // Пункт 1
    while (true) {
        int counter = 0;
        int helper_counter = 0;
        bool flag = true;
        int choice_target;
        int num;
        int size_vector;
        int choice_index;
        cout << "Введите цифру 0-6 (7 - доп задание): ";
        cin >> choice_target;

        switch (choice_target) {
        case 0:
            cout << "Выход..." << endl;
            break;
        case 1:
            print_vector(vec);
            break;
        case 2:
            cout << "Введите число для добавления в начало: ";
            cin >> num;
            vec.reserve(vec.size() + 1);
            vec.insert(vec.begin(), num);
            break;
        case 3:
            cout << "Введите число для добавления в конец: " << endl;
            cin >> num;
            vec.reserve(vec.size()+1);
            vec.push_back(num);
            break;
        case 4:
            cout << "Очистка массива..." << endl;
            size_vector = vec.size();
            for (int i = 0; i < size_vector; i++) {
                vec.pop_back();
            }
            break;
        case 5:
            cout << "Введите индекс элемента: ";
            cin >> choice_index;
            if (choice_index < vec.size() - 1 && choice_index >= 0) {
                cout << vec[choice_index] << endl;
            }
            else {
                cout << "Элемента с таким индексом нет" << endl;
            }
            break;
        case 6:
            print_vector(vec);
            size_vector = vec.size();
            for (int i=0; i < size_vector; i++) {
                if (vec[i] % 2 == 0) {
                    vec[i] = vec[i] + 2;
                }
                else {
                    vec[i] = vec[i] * (-1);
                }
            }
            print_vector(vec);
            break;
        case 7:
            cout << "Введите значение К: ";
            cin >> num;
            for (int i = 1; counter < num; i++) {
                helper_counter += 1;
                counter += i;
                if (counter > num) {
                    flag = false;
                }
            }
            if (flag) {
                for (int i = 1; i <= helper_counter; i++) {
                    if (i % 2 == 0) {
                        vec.reserve(vec.size() + 1);
                        vec.push_back(i);
                    }
                    else {
                        if (helper_counter % 2 == 0) {
                            vec.reserve(vec.size() + 1);
                            vec.insert(vec.begin(), helper_counter - i);
                        }
                        else {
                            vec.reserve(vec.size() + 1);
                            vec.insert(vec.begin(), helper_counter - i + 1);
                        }
                    }
                }
            }
            else {
                size_vector = vec.size();
                for (int i = 0; i < size_vector; i++) {
                    if (i % 2 == 0) {
                        vec.reserve(vec.size() + 1);
                        vec.push_back(vec[i]);
                    }
                }
            }
            print_vector(vec);


            break;
        default:
            cout << "Выбрано число вне диапазона" << endl;
        }
        if (choice_target == 0) {
            break;
        }
    }

    // Пункт 2
    array<int, 10> arr;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-10, 10);
    for (int i = 0; i < 10; i++) {
        arr[i] = dis(gen);
    }
    sort_array_value(arr);
    sort_array_link(arr);
    sort_array_indicator(&arr);
    cout << endl;
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }


    // Пункт 3
    // В 1 пункте выбрал std::vector, потому что std::array это статичный массив.
    // Выбора нет потому что во втором пункте массив не изменяется, а в первом может увеличиваться или уменьшаться,
    // следовательно в первом нельзя использовать std::array
    // std::vector и std::array выполняют одинаковую роль, когда массив статичен и не будет меняться

    return 0;
}
