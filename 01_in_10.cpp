#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string InputInt() { // функция обработки ввода
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

		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '1' && s[i] != '0') {
				prove = false;
				break;
			}
		}
		if (!prove) {
			cout << "Введите число в двоичной системе: ";
			continue;
		}
		return s;
	}
}

void decimal_research() { // функция перевода из двоичного числа в десятичное
	cout << "Введите число: ";
	string num = InputInt();
	cout << "Ваше число: " << num << "\n";

	reverse(num.begin(), num.end());
	long long result = 0;
	long long go_of_two = 1;

	for (int i = 0; i < num.length(); i++) { // цикл перевода числа
		if (num[i] == '1') {
			result += go_of_two;
		}
		go_of_two *= 2;
	}
	cout << "\nРезультат операции: " << result;
	/*
	for (int i = 0; i < num.length(); i++) {
		char a = num[i];
		int b = a - '0';

		result += (b * pow(2, i));
	}
	*/
}

int main() {
	int x;
	cout << "Допустимый алфавит: 0 и 1" << endl;
	cout << "Введите число: ";
	decimal_research();

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
			decimal_research();
		}
	}
	return 0;
}