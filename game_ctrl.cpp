#include "game_ctrl.h"
#include <iostream>

using namespace std;

void GameController::startGame() {
    int size;
    do {
        cout << "Введіть розмір поля (" << MIN_SIZE << "-" << MAX_SIZE << "): ";
        cin >> size;
        cin.ignore();
        if (size<MIN_SIZE || size>MAX_SIZE) {
            cout << "Невірний розмір. Спробуйте ще раз." << endl;
        }
    } while (size < MIN_SIZE || size > MAX_SIZE);

    field.init(size);
    moveCount = 0;
    gameLoop();
}

int GameController::processInput() {
    cout << "Введіть номер фішки (пробіл = вихід): ";
    char ch;
    cin.get(ch);
    if (ch == ' ') return 32;
    cin.putback(ch);
    int tile;
    cin >> tile;
    cin.ignore();
    return tile;
}

void GameController::gameLoop() {
    while (field.state == Active) {
        cout << "\n";
        cout << field;
        int input = processInput();
        if (input == 32) {
            field.state = Interrupted;
            cout << "\nГру перервано." << endl;
            break;
        }
        bool moved = field ^ input;
        if (!moved) {
            cout << "Неможливо перемістити фішку " << input << endl;
        }
        else {
            moveCount++;
        }
        if (field.checkWin()) {
            field.state = Win;
            cout << "\n";
            cout << field;
            cout << "Вітаємо! Ви виграли за " << moveCount << " ходів." << endl;
        }
    }
}
