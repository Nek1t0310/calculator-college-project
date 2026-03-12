#include<iostream>
#include<string>
//#include<cmath>
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

		for (int i = 0; i < s.length(); i++) { // обработка допустимого алфавита
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

void decimal_research() { // функция перевода из двоичного числа в десятичное, вход: строковая переменная, выход: целочисленная переменная
	cout << "Введите число: ";
	string num = InputInt();

	reverse(num.begin(), num.end());
	long long result = 0;
	long long go_of_two = 1; // переменная аккумулятор степени двоичного числа при переводе в десятичное

	for (int i = 0; i < num.length(); i++) { // цикл перевода числа
		if (num[i] == '1') {
			result += go_of_two;
		}
		go_of_two *= 2;
	}
	cout << "\nЧисло в десятичной системе: " << result;
	/*
	for (int i = 0; i < num.length(); i++) {
		char a = num[i];
		int b = a - '0';

		result += (b * pow(2, i));
	}
	*/ // not blazing code, because pow
}

int main() {
	int x;
	cout << "Допустимый алфавит: 0 и 1" << endl;
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
			decimal_research();
		}
	}
	return 0;
}
