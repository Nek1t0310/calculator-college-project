#include<iostream>
#include<string>
using namespace std;

// валидация ввода десятичного числа
// разрешённый алфавит: 0-9
string InputInt() { 
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
			if (!isdigit(c)) { // проверка допустимого для этой системы алфавита 
				prove = false;
				break;
			}
		}
		if (!prove) {
			cout << "Введите число в десятичной системе: ";
			continue;
		}
		
		return s;
	}
}

// валидация ввода двоичного числа
// разрешённый алфавит: 0, 1
string InputBin() {
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

		for (int i = 0; i < s.length(); i++) { // обработка допустимого для этой системы алфавита
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

// валидация ввода восьмеричного числа
// разрешённый алфавит: 0-7
string InputOctal() {
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

		for (int i = 0; i < s.length(); i++) { // обработка допустимого для этой системы алфавита
			if (!(s[i] >= '0' && s[i] <= '7')) {
				prove = false;
				break;
			}
		}
		if (!prove) {
			cout << "Введите число в восьмеричной системе: ";
			continue;
		}
		return s;
	}
}

// валидация шестнадцатиричного числа
// разрешённый алфавит: A-F, 0-9
string InputHex() {
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

		for (int i = 0; i < s.length(); i++) { // обработка допустимого для этой системы алфавита
			if (!isxdigit(s[i])) {
				prove = false;
				break;
			}
						s[i] = toupper(s[i]);
		}
		if (!prove) {
			cout << "Введите число в шестнадцатиричной системе: ";
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

// функция перевода из двоичного числа в десятичное 
//вход: строковая переменная, выход: целочисленная переменная
long long decimal_research_from_binary(string num) { 

	reverse(num.begin(), num.end());
	long long result = 0;
	long long go_of_two = 1; // переменная аккумулятор степени двоичного числа 

	for (int i = 0; i < num.length(); i++) { // цикл перевода числа
		if (num[i] == '1') {
			result += go_of_two;
		}
		go_of_two *= 2;
	}
	//cout << "\nЧисло в десятичной системе: " << result << "\n";
	return result;
}

// функция перевода из восьмеричного числа в десятичное 
//вход: строковая переменная, выход: целочисленная переменная
long long decimal_research_from_octal(string num) { 

	reverse(num.begin(), num.end());
	long long result = 0;
	long long go_of_eight = 1; // переменная аккумулятор степени восьмеричного числа

	for (int i = 0; i < num.length(); i++) {
		long long digit = num[i] - '0';
		result += digit * go_of_eight;
		go_of_eight *= 8; // умножение на степень соответствующую разряду числа
	}

	//cout << "Число в десятичной системе: " << result << "\n";
	return result;
}

// функция перевода из шестнадцатиричного числа в десятичное 
//вход: строковая переменная, выход: целочисленная переменная
long long decimal_research_from_hex(string num) { 

	reverse(num.begin(), num.end());
	long long result = 0;
	long long go_of_hex = 1;

	for (int i = 0; i < num.length(); i++) {
		long long digit;
		if (isdigit(num[i])) {
			digit = num[i] - '0';
		} else {
			digit = num[i] - 'A' + 10;
		}
		result += digit * go_of_hex;
		go_of_hex *= 16;
	}

	return result;
}

long long to_long_long(string num) {
	return stoll(num);
}

// перевод в двоичную систему
void binary_research(long long num) { 
	string number_01 = "";

	do {
		number_01 += to_string(num % 2);
		num /= 2;
	} while (num > 0);

	reverse(number_01.begin(), number_01.end()); // расположение элементов: от старшего бита к младшему
	cout << "Это число в двоичной системе: " << number_01;
}

// перевод в восьмеричную систему
void octal_research(long long num) { 
	string result = "";

	do {
		result += to_string(num % 8);
		num /= 8;
		//cout << num << endl;
	} while (num > 0);

	reverse(result.begin(), result.end());
	cout << "Это число в восьмеричной системе: " << result;
}

// перевод в шестнадцатеричную систему
void hex_research_blazing(long long num) {
	string result = "";
	const char* digits = "0123456789ABCDEF";

	do {
		result += digits[num % 16];
		num /= 16;
	} while (num > 0);

	reverse(result.begin(), result.end());
	cout << "Это число в шестнадцатеричной системе: " << result;
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

		string num;
		long long decimal_num = 0;
		cout << "Введите число в " << M << "-й системе: ";

		// перевод числа из указанной системы в десятичную, некий мост для связи входной системы и конечной
		if (M == 2) {											 
			num = InputBin();									 
			decimal_num = decimal_research_from_binary(num);     
		}														 
		else if (M == 8) {										 
			num = InputOctal();									 
			decimal_num = decimal_research_from_octal(num);		 
		}														 
		else if (M == 10) {										
			num = InputInt();									 
			decimal_num = stoll(num);							 
		}														 
		else if (M == 16) {										 
			num = InputHex();									 
			decimal_num = decimal_research_from_hex(num);
		}														 

		cout << "Введите конечную систему: ";
		int N = system_check();
		cout << "Вы выбрали систему: " << N << endl;

		if (N == 2) {
			binary_research(decimal_num);
		}
		else if (N == 8) {
			octal_research(decimal_num);
		}
		else if (N == 10) {
			cout << "Это число в " << N << "-й системе: " << decimal_num << endl;
		}
		else if (N == 16) {
			hex_research_blazing(decimal_num);
		}
		cout << "\nВы хотите завершить программу? \n";
		cout << "1 - да, 0 - нет\n";
		int x;
		cin >> x;
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