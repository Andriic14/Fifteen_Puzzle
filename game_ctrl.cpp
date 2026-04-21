#include "game_ctrl.h"
#include <iostream>
#include <stdexcept>

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

    if (!isdigit(ch)) {
        cin.ignore(1000, '\n');
        throw runtime_error("Некоректний ввід, введіть число або пробіл.");
    }

    cin.putback(ch);
    int tile;
    cin >> tile;
    cin.ignore();
    if (tile < 1 || tile > field.size * field.size - 1) {
        throw runtime_error("Номер фішки поза допустимим діапазоном");
    }
    return tile;
}

void GameController::gameLoop() {
    while (field.state == Active) {
        cout << "\n";
        cout << field;

        try{
            int input = processInput();
            if (input == 32) {
                field.state = Interrupted;
                cout << "\nГру перервано." << endl;
                break;
            }
            bool moved = field ^ input;
            moveCount++;
            if (field.checkWin()) {
                field.state = Win;
                cout << "\n";
                cout << field;
                cout << "Вітаємо! Ви виграли за " << moveCount << " ходів." << endl;
            }
        }
        catch (const runtime_error& e) {
            cout << "Помилка: " << e.what() << endl;
            cout << "Спробуйте ще раз." << endl;
        }
    }
}
