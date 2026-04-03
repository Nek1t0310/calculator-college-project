#include<iostream>
#include<string>
using namespace std;

// валидация ввода разных чисел(2, 8, 10, 16)
string InputCheck(int base) {
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

		if (base == 2) {
			for (int i = 0; i < s.length(); i++) { // обработка допустимого для двоичной системы алфавита
				if (s[i] != '1' && s[i] != '0') {
					prove = false;
					break;
				}
			}
		}
		else if (base == 8) {
			for (int i = 0; i < s.length(); i++) { // обработка допустимого для восьмеричной системы алфавита
				if (!(s[i] >= '0' && s[i] <= '7')) {
					prove = false;
					break;
				}
			}
		}
		else if (base == 10) {
			for (char c : s) {
				if (!isdigit(c)) { // проверка допустимого для десятичной системы алфавита 
					prove = false;
					break;
				}
			}
		}
		else if (base == 16) {
			for (int i = 0; i < s.length(); i++) { // обработка допустимого для шестнадцатиричной системы алфавита
				if (!isxdigit(s[i])) {
					prove = false;
					break;
				}
				s[i] = toupper(s[i]);
			}
		}
		if (!prove) {
			cout << "Введите число в " << base <<"-й системе: ";
			continue;
		}
		return s;
	}
}

// валидация систем исчисления
int system_check() {
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

		if (s == "2" || s == "8" || s == "10" || s == "16") { // проверка допустимых символов
			prove = true;
		} else prove = false;

		if (!prove) {
			cout << "Введите систему из списка: ";
			continue;
		}
		int value = stoi(s); // перевод проверенного ввода обратно в переменную типа long long
		return value;
	}
}

// перевод из любой системы(2, 8, 10, 16) в десятичную(2)
// вход: строковая переменная, выход: целочисленная переменная
long long decimal_research_from_any(int base, string num) {

	reverse(num.begin(), num.end());
	long long result = 0;
	long long go_of_any = 1; // переменная аккумулятор степени двоичного числа 

	if (base == 2) {
		for (int i = 0; i < num.length(); i++) { // цикл перевода числа в двоичную систему
			if (num[i] == '1') {
				result += go_of_any;
			}
			go_of_any *= base;
		}
	}
	else if (base == 8) {
		for (int i = 0; i < num.length(); i++) {
			long long digit = num[i] - '0';
			result += digit * go_of_any;
			go_of_any *= base; // умножение на степень соответствующую разряду числа
		}
	}
	else if (base == 16) {
		for (int i = 0; i < num.length(); i++) {
			long long digit;
			if (isdigit(num[i])) {
				digit = num[i] - '0';
			}
			else {
				digit = num[i] - 'A' + 10;
			}
			result += digit * go_of_any;
			go_of_any *= base;
		}
	}
	return result;
} 

// перевод из типа данных string в long long
long long to_long_long(string num) {
	return stoll(num);
}

// перевод с десятичной системы(10) во все остальные(2, 8, 10, 16)
void any_research(long long num_, int base) {
	string number = "";
	const char* digits = "0123456789ABCDEF";

	do {
		number += digits[num_ % base];
		num_ /= base;
	} while (num_ > 0);
	
	reverse(number.begin(), number.end()); // расположение элементов: от старшего элемента к младшему
	cout << "Это число в " << base << "-й системе: " << number;
}

int main() {
	cout << "========================================================================\n";
	cout << "Вас приветствует программа по переводу чисел в разные системы исчисления\n";
	cout << "========================================================================\n\n";
	cout << "Доступные системы исчисления: \n";
	cout << "2 - двоичная\n8 - восьмеричная\n10 - десятичная\n16 - шестнадцатиричная\n\n";

	while (true) {
		cout << "Введите входную систему исчисления: ";
		int M = system_check();
		cout << "Вы выбрали систему: " << M << endl;

		string number;
		long long decimal_num = 0;
		cout << "Введите число в " << M << "-й системе: ";

		// перевод числа из указанной системы в десятичную, некий мост для связи входной системы и конечной
		if (M == 2 || M == 8 || M == 16) {
			number = InputCheck(M);
			decimal_num = decimal_research_from_any(M, number);
		}
		else if (M == 10) {
			number = InputCheck(M);
			decimal_num = to_long_long(number);
		}

		cout << "Введите конечную систему: ";
		int N = system_check();
		cout << "Вы выбрали систему: " << N << endl;

		// перевод из десятичной в конечную
		if (N == 2 || N == 8 || N == 16) {
			any_research(decimal_num, N);
		}
		else if (N == 10) {
			cout << "Это число в " << N << "-й системе: " << decimal_num << endl;
		}
		cout << "\nВы хотите завершить программу? \n";
		cout << "1 - да, 0 - нет\n";
		int x;

		while (true) {
			if (!(cin >> x) || (x > 1 || x < 0)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Введите либо 0, либо 1: ";
				continue;
			} else { 
				break; 
			}
		}
		if (x == 1) {
			cout << "Хорошего дня!" << endl;
			break;
		}
		if (x == 0) {
			continue;
		}
	}
	return 0;
}
