#pragma once
#include "game_field.h"

struct GameController
{
	GameField field;
	int moveCount;
	bool isRunning;
};

// Запускає нову гру: ініціалізує поле, обнуляє лічильник ходів,
void startGame(GameController& ctrl);
// Обробляє введення користувача з клавіатури.
void processInput(GameController& ctrl);
// Виконує хід у вказаному напрямку.
bool makeMove(GameController& ctrl, char direction);
// Перевіряє чи гравець виграв
bool checkWin(const GameController& ctrl);
// Завершує гру
void endGame(GameController& ctrl);
