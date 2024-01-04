#include "mods.h"
class test {
private:
	string s;
public:
	void setS(string s) {
		if (s == "")
			throw string{ "Пустая строка" };
		this->s = s;
	}
	string getS() {
		return this->s;
	}
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int v, c;
	School a;
	while (true) {

		do {
			menu();
			printf("Введите пункт меню: ");
			v = scanf("%d", &c);
			while (getchar() != '\n');
			system("cls");
		} while (c > 8 || c < 1 || v < 1);

		switch (c) {
		case 1: {
			vivod(&a);
			break;
		}
		case 2: {
			create_class(&a);
			break;
		}
		case 3: {
			del(&a);
			break;
		}
		case 4: {
			red_class(&a);
			break;
		}
		case 5: {
			merge(&a);
			break;
		}
		case 6: {
			printN_cl(&a);
			cl();
			break;
		}
		case 7: {
			exit(EXIT_SUCCESS);
			break;
		}
		case 8: {
			string s;
			test t;
			cout << "Введите строку: ";
			getline(cin, s);
			try {
				t.setS(s);
				cout << "Вы ввели: " << t.getS() << endl;
			}
			catch (...) {
				cout << "Ошибка ввода" << endl;
			}
			cl();
		}
		default:
			break;
		}
		/*create_class(&a);
		vivod_scl(&a, a.n_cl);

		vivod_cls(&a, a.n_cl - 1);
		red_class(&a);*/

	}
}