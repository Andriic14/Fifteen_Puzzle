#include <iostream>
#include "game_field.h"
#include "game_ctrl.h"
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "==========================" << endl;
	cout << "    Гра П'ятнашки        " << endl;
	cout << "==========================" << endl;
	
	try {
		GameController ctrl;
		ctrl.startGame();
	}
	catch (const runtime_error& e) {
		cout << "Критична помилка: " << e.what() << endl;
	}
	catch (...) {
		cout << "Невідома помилка. Програма завершена." << endl;
	}
	return 0;
}
