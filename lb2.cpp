#include <iostream>
#include <bitset>
#include <limits>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");

	unsigned short A;
	int i;

	cout << "Введите число (0-255): ";
	cin >> A;

	if (A < 0 || A > 255) {
		cout << "Введено неверное число" << endl;
		return 1;
	}

	cout << "Введите значение i(0 - 7): ";
	cin >> i;

	if (i < 0 || i > 7) {
		cout << "Введено неверное значение для i" << endl;
		return 1;
	}

	bitset<8> binary(A);
	cout << int(A) << " - " << binary.to_string() << endl;

	int S = (A >> i) & 1;
	cout << S << endl;

	if (S == 1) {
		cout << "Бит " << i << " числа А равен 1" << endl;

		int B, C;
		cout << "Введите первое число: ";
		cin >> B;
		cout << "Введите второе число: ";
		cin >> C;

		if (B > C) {
			cout << "Наибольшее число: " << B << endl;
		}
		else {
			cout << "Наибольшее число: " << C << endl;
		}

		/// Поправить
		i = 0;
		cout << (A >> i) << endl;
	}
	else {
		A = ~A;
		bitset<8> binary(A);
		cout << binary.to_string() << endl;

	}
	

	int N;
	cout << "Введите номер месяца: ";
	cin >> N;

	switch (N) {
	case 1:
		cout << "Январь" << endl; break;
	case 2:
		cout << "Февраль" << endl; break;
	case 3:
		cout << "Март" << endl; break;
	case 4:
		cout << "Апрель" << endl; break;
	case 5:
		cout << "Май" << endl; break;
	case 6:
		cout << "Июнь" << endl; break;
	case 7:
		cout << "Июль" << endl; break;
	case 8:
		cout << "Август" << endl; break;
	case 9:
		cout << "Сентябрь" << endl; break;
	case 10:
		cout << "Октрябрь" << endl; break;
	case 11:
		cout << "Ноябрь" << endl; break;
	case 12:
		cout << "Декабрь" << endl; break;
	default:
		cout << "Такого месяца не существует!"; break;
	}
}

