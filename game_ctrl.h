#pragma once
#include "game_field.h"

struct GameController
{
    GameField field;
    int moveCount;

    // Запускає нову гру: ініціалізує поле, обнуляє лічильник ходів
    void startGame();

    // Обробляє введення користувача – повертає введене ціле значення
    int processInput();

    // Основний ігровий цикл
    void gameLoop();
};
