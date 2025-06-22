// tic tac toe
#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void displayBoard() {
    cout << "\n";
    cout << "  1   2   3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << " ---+---+---\n";
    }
    cout << "\n";
}

bool isWin() {
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

    for (int j = 0; j < 3; ++j)
        if (board[0][j] == currentPlayer &&
            board[1][j] == currentPlayer &&
            board[2][j] == currentPlayer)
            return true;

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int row, col;
    bool validMove;

    do {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        validMove = row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ';

        if (!validMove) {
            cout << "Invalid move! Try again.\n";
        }
    } while (!validMove);

    board[row - 1][col - 1] = currentPlayer;
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameEnded = false;

        cout << "=== Tic-Tac-Toe Game ===\n";

        while (!gameEnded) {
            playGame();

            if (isWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameEnded = true;
            } else if (isDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameEnded = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}
