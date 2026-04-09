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

	int size;
	cout << "Введіть розмір поля: ";
	cin >> size;
	cout << "\n";
	GameController ctrl;
	ctrl.field.init(size);

	cout << "Початковий стан поля:" << endl;
	cout << ctrl.field;
	// фішка зліва від порожньої
	int r = size - 1, c = size - 2;
	cout << "\nЧи можна перемістити фішку [" << r << "][" << c << "] = " << ctrl.field.board[r][c] << "?" << endl;
	if (ctrl.field.canMove(r, c)) {
		cout << "Так, хід можливий" << endl;
	}
	else {
		cout << "Ні, хід неможливий" << endl;
	}
	// фішка в кутку
	cout << "\nЧи можна перемістити фішку [0][0] = "
		<< ctrl.field.board[0][0] << "?" << endl;
	if (ctrl.field.canMove(0, 0))
		cout << "Так, хід можливий" << endl;
	else
		cout << "Ні, хід неможливий" << endl;

	// виконання ходу
	int tile = ctrl.field.board[size - 1][size - 2];
	cout << "\nВиконуємо хід — переміщуємо фішку " << tile << ":" << endl;
	ctrl.field ^ tile;
	cout << ctrl.field;


	// ще хід
	int tile2 = ctrl.field.board[size - 2][size - 2];
	cout << "\nВиконуємо хід — переміщуємо фішку " << tile2 << ":" << endl;
	ctrl.field ^ tile2;
	cout << ctrl.field;

	// перевірка виграшу
	cout << "\nПеревірка виграшу після ходів: ";
	if (ctrl.field.checkWin()) {
		cout << "Виграш" << endl;
	}
	else {
		cout << "Гра ще не завершена" << endl;
	}

	// вручну ставимо виграшний стан
	int num = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ctrl.field.board[i][j] = num++;
		}
	}
	ctrl.field.board[size - 1][size - 1] = 0;
	ctrl.field.emptyRow = size - 1;
	ctrl.field.emptyCol = size - 1;

	cout << "\nВиграшний стан поля:" << endl;
	cout << ctrl.field;
	cout << "Перевірка виграшу: ";
	if (ctrl.field.checkWin())
		cout << "Виграш!" << endl;
	else
		cout << "Гра ще не завершена" << endl;

	return 0;
}
