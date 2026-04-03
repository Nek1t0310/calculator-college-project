#include<iostream>
#include<string>
using namespace std;

string InputCheck(int base) { // функция обработки ввода 
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
		int dot_count = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.' || s[i] == ',') {
				dot_count++;
				if (dot_count > 1) {
					prove = false;
					break;
				}
				continue;
			}
		}
		// проверка на наличие символов разделения(  '.'  ','  ) в начале и в конце строки
		if (s.front() == '.' || s.front() == ',' || s.back() == '.' || s.back() == ',') {
			cout << "Введите число корректно: ";
			continue;
		}

		if (base == 2) {
			for (int i = 0; i < s.length(); i++) { // обработка допустимого для двоичной системы алфавита
				if (s[i] != '1' && s[i] != '0' && s[i] != '.' && s[i] != ',') {
					prove = false;
					break;
				}
			}
		}
		else if (base == 8) {
			for (int i = 0; i < s.length(); i++) { // обработка допустимого для восьмеричной системы алфавита
				if (!(s[i] >= '0' && s[i] <= '7') && s[i] != '.' && s[i] != ',') {
					prove = false;
					break;
				}
			}
		}
		else if (base == 10) {
			for (int i = 0; i < s.length(); i++) {
				if (!isdigit(s[i]) && s[i] != '.' && s[i] != ',') { // проверка допустимого для десятичной системы алфавита 
					prove = false;
					break;
				}
			}
		}
		else if (base == 16) {
			for (int i = 0; i < s.length(); i++) { // обработка допустимого для шестнадцатиричной системы алфавита
				if (!isxdigit(s[i]) && s[i] != '.' && s[i] != ',') {
					prove = false;
					break;
				}
				s[i] = toupper(s[i]);
			}
		}

		if (!prove) {
			cout << "Введите число в " << base << "-й системе: ";
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
		}
		else prove = false;

		if (!prove) {
			cout << "Введите систему из списка: ";
			continue;
		}
		int value = stoi(s); // перевод проверенного ввода обратно в переменную типа long long
		return value;
	}
}

long double decimal_research_from_any_double(string num, int base) {
	string num_int = ""; // переменная целой части числа
	string num_float = ""; // переменная дробной части числа
	long double result = 0; // результат 
	long double go_of_any = 1; // переменная аккумулятор для степени числа
	long double go_of_any_float = 1.0L / base; // передаём отрицательное значение степени для перевода дробной части
	int flag = 0;

	for (int i = 0; i < num.length(); ++i) {

		if (num[i] == '.' || num[i] == ',') {
			flag += i; // фиксируем итерацию на которой наткнулись на разделение между целой и дробной частью
			continue;
		}
		if (flag == 0) {
			num_int += num[i];
		}
		if (flag > 0) {
			num_float += num[i];
		}
	}
	reverse(num_int.begin(), num_int.end());

	if (base == 2) {
		// перевод целой части
		for (int i = 0; i < num_int.length(); i++) { // цикл перевода числа в двоичную систему
			if (num_int[i] == '1') {
				result += go_of_any;
			}
			go_of_any *= base;
		}
		// перевод дробной части
		for (int i = 0; i < num_float.length(); i++) {
			if (num_float[i] == '1') {
				result += go_of_any_float;
			}
			go_of_any_float /= base; // увеличиваем отрицательную степень
		}
	}
	else if (base == 8) {
		//перевод целой части
		for (int i = 0; i < num_int.length(); i++) {
			long long digit = num_int[i] - '0';
			result += digit * go_of_any;
			go_of_any *= base; // умножение на степень соответствующую разряду числа
		}
		// перевод дробной части
		for (int i = 0; i < num_float.length(); i++) {
			long long digit = num_float[i] - '0';
			result += digit * go_of_any_float;
			go_of_any_float /= base; // увеличиваем отрицательную степень
		}
	}
	else if (base == 16) {
		// перевод целой части
		for (int i = 0; i < num_int.length(); i++) {
			long long digit;
			if (isdigit(num_int[i])) {
				digit = num_int[i] - '0';
			}
			else {
				digit = num_int[i] - 'A' + 10;
			}
			result += digit * go_of_any;
			go_of_any *= base;
		}
		// перевод дробной части
		for (int i = 0; i < num_float.length(); i++) {
			long long digit;
			if (isdigit(num_float[i])) {
				digit = num_float[i] - '0';
			}
			else {
				digit = num_float[i] - 'A' + 10;
			}
			result += digit * go_of_any_float;
			go_of_any_float /= base; // увеличиваем отрицательную степень
		}
	}
	//cout << "Всё число в десятичной: " << result;
	return result;
}

// перевод из типа данных string в long long
long double to_long_double(string num) {
	return stold(num);
}

void any_research_double(long double num, int base) {
	string int_any = ""; // переменная целой части в выбранной системе 
	string float_any = ""; // переменная дробной части в выбранной системе
	string result = ""; // результат 
	int block = 8;
	const char* digits = "0123456789ABCDEF";
	// const long double EPS = 1e-12; // расширяем порог сравнения 

	long long num_int_long = (long long)num;
	long double num_float_long = num - num_int_long;

	do {
		int_any += digits[num_int_long % base];
		num_int_long /= base;
	} while (num_int_long > 0);

	while (num_float_long > 0 && block > 0) {
		num_float_long *= base;

		long long int_part_frac = (long long)num_float_long; // отделяем целую часть от дробного числа при сборке
		// обработка случая с плавающей точкой long double
		if (int_part_frac >= base) {
			int_part_frac = base - 1;
			num_float_long = 0;
		}

		float_any += digits[int_part_frac];
		num_float_long -= int_part_frac; // отнимаем от дробного числа целую часть, что бы продолжать дальнейший перевод

		if (num_float_long < 0) {
			num_float_long = 0;
		}
		block--; // ограничение для записи
	}

	reverse(int_any.begin(), int_any.end());
	result += int_any;
	if (!float_any.empty()) {
		result += ".";
		result += float_any;
	}
	cout << "Ваше число в " << base << "-ой системе: " << result << endl;
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
		long double decimal_num = 0;
		cout << "Введите число в " << M << "-й системе: ";

		// перевод числа из указанной системы в десятичную, некий мост для связи входной системы и конечной
		if (M == 2 || M == 8 || M == 16) {
			number = InputCheck(M);
			decimal_num = decimal_research_from_any_double(number, M); // перевод в десятичную
		}
		else if (M == 10) {
			number = InputCheck(M);
			decimal_num = to_long_double(number);
		}

		cout << "Введите конечную систему: ";
		int N = system_check();
		cout << "Вы выбрали систему: " << N << endl;

		// перевод из десятичной в конечную
		if (N == 2 || N == 8 || N == 16) {
			any_research_double(decimal_num, N);
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
				cout << "Введите либо 0, лобо 1: ";
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
