#pragma once
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
    // Виводить поточний стан поля у консоль
    void print() const;
    // Звільняє динамічну пам'ять
    void freeField();
    // Перемішує фішки для початку нової гри
    void shuffleField();
    // Перевірка можливості ходу
    bool canMove(int row, int col) const;
    // Виконання ходу
    void makeMove(int tile);
    // Перевірка умови виграшу
    bool checkWin() const;
};
