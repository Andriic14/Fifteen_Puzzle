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
	cout << "Розмір поля від " << MIN_SIZE << " до " << MAX_SIZE << endl;
	GameController ctrl;
	return 0;
}