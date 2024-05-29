#include <iostream>
using namespace std;

int player1 = 0, player2 = 0;

void checkWinner(int currentPlayer) {
    if (currentPlayer % 2 == 0) {
        cout << "Player 2 wins!" << endl;
        player2++;
    } else {
        cout << "Player 1 wins!" << endl;
        player1++;
    }
}

void annulate(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int currentPlayer = 1;

    while (true) {
        int row, column;
        cout << "Enter the field (row and column): ";
        cin >> row >> column;

        // Проверка границ массива
        if (row < 0 || row >= 3 || column < 0 || column >= 3) {
            cout << "Please enter values between 0 and 2" << endl;
            continue;
        }

        // Проверка, что поле пустое
        if (board[row][column] != ' ') {
            cout << "Occupied. Please choose another one." << endl;
            continue;
        }

        // Установка отметки игрока
        if (currentPlayer % 2 == 0) {
            board[row][column] = 'X';
        } else {
            board[row][column] = 'O';
        }

        // Отображение поля
        printBoard(board);

        // Проверка на победу
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
                checkWinner(currentPlayer);
                cout << "Player 1:" << player1 << '|' << "Player 2:" << player2 << endl;
                annulate(board);
                currentPlayer = 1;
                continue;
            }
        }
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
            checkWinner(currentPlayer);
            cout << "Player 1:" << player1 << '|' << "Player 2:" << player2 << endl;
            annulate(board);
            currentPlayer = 1;
            continue;
        }

        // Проверка на ничью
        bool draw = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    draw = false;
                }
            }
        }
        if (draw) {
            cout << "Draw!" << endl;
            annulate(board);
            currentPlayer = 1;
            continue;
        }

        // Переход хода к следующему игроку
        currentPlayer++;
    }

    return 0;
}
