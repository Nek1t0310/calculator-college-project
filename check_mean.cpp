#include<iostream>
#include<string>
#include<iterator>
using namespace std;

void check_1() // функция обработки символов
{
	cout << "Введите сообщение: ";
	while (true) {

		if (cin.peek() == '\n') {
			cin.ignore();
		}

		string str;
		getline(cin, str);

		if (str.empty()) {
			cout << "Пустой ввод, повторите: ";
			continue;
		}

		bool prove = true;

		for (char c : str) { // основной цикл проверки
			if (!isdigit(c) && !isalpha(c)) { // проверка допустимых символов: A - Z, a - z, 0 - 9
				prove = false;
				break;
			}
		}
		if (!prove) {
			cout << "Ваше сообщение не соответствует алфавиту, введите заново: \n";
			continue;
		}

		cout << "Ваше сообщение соответствует алфавиту: " << str << endl;
		return;
	}
}

int main() {
	int x;
	cout << "Допустимый алфавит: A - Z, a - z, 0 - 9" << endl;
	check_1();

	while (true) {
		int x;
		cout << "Вы хотите завершить программу?\n";
		cout << "1 - да, 0 - нет\n";
		
		if (!(cin >> x) || (x > 1 || x < 0)) {
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (x == 1) {
			cout << "Хорошего дня!" << endl;
			break;
		}
		if (x == 0) {
			check_1();
		}
	}
	return 0;
}
