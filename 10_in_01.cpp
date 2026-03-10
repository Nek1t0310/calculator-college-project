#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long long InputInt() { // функция обработки ввода 
	while (true) {

		if (cin.peek() == '\n') {
			cin.ignore();
		}

		string s;
		getline(cin, s);

		if (s.empty()) {
			cout << "\nПустой ввод, повторите: ";
			continue;
		}

		bool prove = true;

		for (char c : s) {
			if (!isdigit(c)) { // проверка допустимых символов
				prove = false;
				break;
			}
		}
		if (!prove) {
			cout << "Введите число: ";
			continue;
		}
		long long value = stoll(s); // перевод проверенного ввода обратно в переменную типа long long
		return value;
	}
}

void binary_research() { // функция перевода в двоичное число
	long long num = InputInt();

	string number_01 = "";

	do {
		number_01 += to_string(num % 2);
		num /= 2;
	} while (num > 0);

	reverse(number_01.begin(), number_01.end()); // расположение элементов: от старшего бита к младшему
	cout << "Это число в двоичной системе: " << number_01;
}

void binary_research_int() { // такая же функция только с итерациями в массивах
	long long num = InputInt();

	int numbers[64];
	int i = 0;

	do {
		numbers[i] = num % 2;
		num /= 2;
		i++;
	} while (num > 0);

	cout << "Это число в двоичной системе: ";
	for (int j = i - 1; j >= 0; j--) { // расположение элементов: от старшего бита к младшему
		cout << numbers[j];
	}
}

int main() {
	int x;
	cout << "Допустимый алфавит: 0 - 9" << endl;
	cout << "Введите число: ";
	binary_research();

	while (true) {
		int x;
		cout << "\nВы хотите завершить программу?\n";
		cout << "1 - да, 0 - нет\n";
		cin >> x;
		if (x == 1) {
			cout << "Хорошего дня!" << endl;
			break;
		}
		if (x == 0) {
			cout << "Введите число: ";
			binary_research();
		}
	}
	return 0;
}