#include <iostream>
#include <vector>

using namespace std;

// Function to print the current state of the board
void printBoard(const vector<vector<char> >& board) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check for a win condition
bool checkWin(const vector<vector<char> >& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Row check
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  // Column check
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Diagonal from top-left to bottom-right
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {  // Diagonal from top-right to bottom-left
        return true;
    }

    return false;
}

// Function to check if the board is full (draw condition)
bool isBoardFull(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // There is still an empty spot
            }
        }
    }
    return true; // No empty spots left, it's a draw
}

// Function to handle a player's move
bool makeMove(vector<vector<char> >& board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false; // If the cell is already occupied, move is invalid
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y') {
        vector<vector<char> > board(3, vector<char>(3, ' ')); // 3x3 grid initialized with empty spaces
        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            // Display the current state of the board
            printBoard(board);

            // Prompt the current player for their move
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column 0-2): ";
            cin >> row >> col;

            // Validate input range
            if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                if (makeMove(board, row, col, currentPlayer)) {
                    // Check if the current player has won
                    if (checkWin(board, currentPlayer)) {
                        printBoard(board);
                        cout << "Player " << currentPlayer << " wins!" << endl;
                        gameOver = true;
                    }
                    // Check if the board is full (draw)
                    else if (isBoardFull(board)) {
                        printBoard(board);
                        cout << "It's a draw!" << endl;
                        gameOver = true;
                    }
                    // Switch players for the next turn
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                } else {
                    cout << "Invalid move! Try again." << endl;
                }
            } else {
                cout << "Invalid input! Please enter row and column values between 0 and 2." << endl;
            }
        }

        // Ask the players if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing! Goodbye!" << endl;
    return 0;
}


