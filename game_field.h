#pragma once
#include <ostream>
#define MIN_SIZE 3
#define MAX_SIZE 8

enum GameState {
	Active,
	Win,
	Interrupted
};

struct GameField
{
    int** board;
    int size;

    // Координати порожньої клітинки
    int emptyRow;
    int emptyCol;

    GameState state; // стан гри

    // Ініціалізація поля (виділяє пам'ять, заповнює числами)
    void init(int d); 
    // Звільняє динамічну пам'ять
    void freeField();
    // Перемішує фішки для початку нової гри
    void shuffleField();
    // Перевірка можливості ходу
    bool canMove(int row, int col) const;

    // Оператор ^ для виконання ходу (замість makeMove)
    // Виконання ходу
    bool operator^(int tile);

    // Перевірка умови виграшу
    bool checkWin() const;
};
// Зовнішня функція перевантаження оператора
std::ostream& operator<<(std::ostream& out, const GameField& field);
