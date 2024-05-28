#include <iostream>
using namespace std;

// void initializeBoard(char board[3][3]);
// void displayBoard(const char board[3][3]);
// bool checkWin(const char board[3][3], char player);
// bool checkDraw(const char board[3][3]);
// void playerMove(char board[3][3], char player);
// bool isValidMove(const char board[3][3], int row, int col);

// Function to initialize the game board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';                                               //initializing the board matrix with space 
        }
    }
}

// Function to display the current state of the game board
void displayBoard(const char board[3][3]) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) 
                cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl;
    }
}

//checking if move is valid
bool isValidMove(const char board[3][3], int row, int col) 
{
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';          //the entered value is valid as it resides under the board value. Also at that place no move is done.
}

//handling player's move
void playerMove(char board[3][3], char player) {
    int row, col;
    bool validMove = false;
    do {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;
        validMove = isValidMove(board, row, col);
        if (!validMove) {
            cout << "Invalid move. Try again." << endl;
        }
    } while (!validMove);                                                                //the loop will continue until we encountered a valid move.
    board[row][col] = player;
}

//check for a win condition
bool checkWin(const char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;                                                                       //all rows or colm contains the same symbol of either player.
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check for a draw condition
bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {                                                        //if any place is empty.
                return false;
            }
        }
    }
    return true;                                                                     //if all places occupied still no win condn that means its a tie.
}


int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool Won = false;
    bool Draw = false;
    char playAgain;

    do {
        initializeBoard(board);
        Won = false;
        Draw = false;

        while (!Won && !Draw) {
            displayBoard(board);
            playerMove(board, currentPlayer);
            Won = checkWin(board, currentPlayer);
            if (!Won) {
                Draw = checkDraw(board);
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        displayBoard(board);

        if (Won) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (Draw) {
            cout << "The game is a draw!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
