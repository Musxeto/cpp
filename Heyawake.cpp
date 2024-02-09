#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants
const int BOARD_SIZE = 6;
const int BLOCK_SIZE = 2;

// Function prototypes
void initializeBoard(vector<vector<int>> &board);
void printBoard(const vector<vector<int>> &board);
bool isValidMove(const vector<vector<int>> &board, int row, int col, int value);
bool isComplete(const vector<vector<int>> &board);
bool solveBoard(vector<vector<int>> &board, int row, int col);

int main() {
    srand(static_cast<unsigned>(time(0)));

    // Initialize the board
    vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));
    initializeBoard(board);

    // Print the initial board
    printBoard(board);

    // Solve the Heyawake puzzle
    if (solveBoard(board, 0, 0)) {
        cout << "\nSolution:\n";
        printBoard(board);
    } else {
        cout << "\nNo solution found.\n";
    }

    return 0;
}

void initializeBoard(vector<vector<int>> &board) {
    // Initialize the board with random values (1 or 2) for blocks
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = rand() % BLOCK_SIZE + 1;
        }
    }
}

void printBoard(const vector<vector<int>> &board) {
    // Print the current state of the board
    cout << "\n  ";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i + 1 << " ";
    }
    cout << "\n";

    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << (board[i][j] == 1 ? '#' : ' ') << " ";
        }
        cout << "\n";
    }
}

bool isValidMove(const vector<vector<int>> &board, int row, int col, int value) {
    // Check if placing the given value at the specified position is valid
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE &&
            board[row][col] == value);
}

bool isComplete(const vector<vector<int>> &board) {
    // Check if the board is complete
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool solveBoard(vector<vector<int>> &board, int row, int col) {
    // Check if the board is complete
    if (isComplete(board)) {
        return true;
    }

    // Try placing values (1 or 2) in empty cells
    for (int value = 1; value <= BLOCK_SIZE; ++value) {
        if (isValidMove(board, row, col, value)) {
            // Make the move
            board[row][col] = value;

            // Move to the next cell
            int nextRow = row + (col + 1) / BOARD_SIZE;
            int nextCol = (col + 1) % BOARD_SIZE;

            // Recursively solve the next cell
            if (solveBoard(board, nextRow, nextCol)) {
                return true;
            }

            // Backtrack if the current move doesn't lead to a solution
            board[row][col] = 0;
        }
    }

    return false;
}

