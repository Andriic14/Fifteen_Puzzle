#pragma once
#include "game_field.h"
#include <fstream>
struct GameController
{
    GameField field;
    int moveCount;

    std::ofstream logFile;

    // Запускає нову гру: ініціалізує поле, обнуляє лічильник ходів
    void startGame();

    // Обробляє введення користувача – повертає введене ціле значення
    int processInput();

    // Основний ігровий цикл
    void gameLoop();
};
