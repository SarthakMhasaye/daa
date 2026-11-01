#include <iostream>

using namespace std;
const int MAX_N = 10; 
char board[MAX_N][MAX_N];
int solutionCount = 0;
void printBoard(int n) {
    solutionCount++;
    cout << "Solution #" << solutionCount << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
// Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
// Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}
// Recursive function to solve the N-Queens problem
void solveNQueens(int row, int n) {
    if (row == n) {
        printBoard(n);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(row + 1, n);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }
    solveNQueens(0, n);

    cout << "Total solutions found: " << solutionCount << "\n";
    return 0;
}
