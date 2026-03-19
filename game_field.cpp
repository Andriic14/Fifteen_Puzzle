#include "game_field.h"
#include <iostream>
#include <iomanip>

using namespace std;

void GameField::init(int d) {
	size = d;
	board = new int* [d];
	for (int i = 0; i < d; i++) {
		board[i] = new int[d];
	}
	int num = size * size - 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = num;
			num--;
		}
	}

	board[size - 1][size - 1] = 0;
	emptyRow = size - 1;
	emptyCol = size - 1;
	if (size % 2 == 0) {
		int temp = board[size - 1][size - 2];
		board[size - 1][size - 2] = board[size - 1][size - 3];
		board[size - 1][size - 3] = temp;
	}

	state = Active;
}

void GameField::print() const {
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				cout << setw(3) << "_";
			}
			else {
				cout << setw(3) << board[i][j];
			}
		}
		cout << endl;
	}
}

void GameField::freeField() {}

void GameField::shuffleField() {}

bool GameField::canMove(int row, int col) const { return false; }

void GameField::makeMove(int tile) {}

bool GameField::checkWin() const { return false; }
