#pragma once
#define MIN_SIZE 3
#define MAX_SIZE 8

struct GameField
{
	int** board;
	int size;
	// Координати порожньої клітинки
	int emptyRow;
	int emptyCol;
};

// Ініціалізація поля(виділяє пам'ять, заповнює числами)
void initField(GameField& field, int size);
// Виводить поточний стан поля у консоль
void printField(const GameField& field);
// Звільняє динамічну пам'ять
void freeField(GameField& field);
// Перемішує фішки для початку нової гри
void shuffleField(GameField& field);
