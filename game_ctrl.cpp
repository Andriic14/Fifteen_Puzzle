#include "game_ctrl.h"
#include <iostream>
#include <stdexcept>
#include <ctime>

using namespace std;

string currentTime() {
    time_t now = time(0);
    tm localT;
    localtime_s(&localT, &now);
    char buf[20];
    strftime(buf, sizeof(buf), "%H:%M:%S", &localT);
    return string(buf);
}

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

    logFile.open("game_log.txt");
    if (!logFile.is_open()) {
        cout << "Помилка: не вдалося створити лог-файл." << endl;
    }
    else {
        logFile << "[" << currentTime() << "] Гра розпочата. " << "Розмір поля: " << size << endl;
        logFile << "[" << currentTime() << "] Початковий стан поля:" << endl;
        logFile << field;
    }
    gameLoop();
    if (logFile.is_open()) {
        logFile.close();
    }
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
                if (logFile.is_open()) {
                    logFile << "[" << currentTime() << "] "<< "Гра завершена. Статус: Зупинка. "<< "Ходів: " << moveCount << endl;
                }
                break;
            }
            bool moved = field ^ input;
            moveCount++;

            if (logFile.is_open()) {
                logFile << "[" << currentTime() << "] "<< "Хід: фішка " << input << endl;
                logFile << "[" << currentTime() << "] "<< "Стан поля після ходу:" << endl;
                logFile << field;
            }

            if (field.checkWin()) {
                field.state = Win;
                cout << "\n";
                cout << field;
                cout << "Вітаємо! Ви виграли за " << moveCount << " ходів." << endl;

                if (logFile.is_open()) {
                    logFile << "[" << currentTime() << "] "<< "Гра завершена. Статус: Виграш. "<< "Ходів: " << moveCount << endl;
                }
            }
        }
        catch (const runtime_error& e) {
            cout << "Помилка: " << e.what() << endl;
            cout << "Спробуйте ще раз." << endl;
            if (logFile.is_open()) {
                logFile << "[" << currentTime() << "] Помилка: "<< e.what() << endl;
            }
        }
    }
}
