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

void GameField::freeField() {
	for (int i = 0; i < size; i++) {
		delete[] board[i];
	}
	delete[] board;
	board = nullptr;
}

void GameField::shuffleField() {}

bool GameField::canMove(int row, int col) const { 
	if (row - 1 == emptyRow && col == emptyCol) return true;
	if (row + 1 == emptyRow && col == emptyCol) return true;
	if (row == emptyRow && col - 1 == emptyCol) return true;
	if (row == emptyRow && col + 1 == emptyCol) return true;
	return false; 
}

bool GameField::operator^(int tile) {
	int tileRow = -1, tileCol = -1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == tile) {
				tileRow = i;
				tileCol = j;
			}
		}
	}
	if (tileRow == -1) return false;
	if (!canMove(tileRow, tileCol)) return false;
	board[emptyRow][emptyCol] = tile;
	board[tileRow][tileCol] = 0;

	emptyRow = tileRow;
	emptyCol = tileCol;

	return true;
}

bool GameField::checkWin() const { 
	int expected = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == size - 1 && j == size - 1) {
				return board[i][j] == 0;
			}
			if (board[i][j] != expected) return false;
			expected++;
		}
	}
	return false; 
}

std::ostream& operator<<(std::ostream& out, const GameField& field) {
	for (int i = 0; i < field.size; i++) {
		for (int j = 0; j < field.size; j++) {
			if (field.board[i][j] == 0) {
				out << setw(3) << "_";
			}
			else {
				out << setw(3) << field.board[i][j];
			}
		}
		out << endl;
	}
	return out;
}
