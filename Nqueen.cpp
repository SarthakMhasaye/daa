#include <iostream>
#include <vector>
#include <string>
using namespace std;
class NQueensSolver {
private:
    int n;
    int solutionCount;
    vector<bool> cols;
    vector<bool> mainDiag;
    vector<bool> antiDiag;
    vector< string> board;
    void printBoard() {
        cout << "Solution #" << solutionCount << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void solve(int row) {
        if (row == n) {
            solutionCount++;
            printBoard();
            return;
        }
        for (int col = 0; col < n; ++col) {
            int mdIdx = row - col + (n - 1);
            int adIdx = row + col;
            if (!cols[col] && !mainDiag[mdIdx] && !antiDiag[adIdx]) {
                board[row][col] = 'Q';
                cols[col] = mainDiag[mdIdx] = antiDiag[adIdx] = true;

                solve(row + 1);

                board[row][col] = '.';
                cols[col] = mainDiag[mdIdx] = antiDiag[adIdx] = false;
            }
        }
    }
public:
    NQueensSolver(int size) : n(size), solutionCount(0) {
        cols.assign(n, false);
        mainDiag.assign(2 * n - 1, false);
        antiDiag.assign(2 * n - 1, false);
        board.assign(n,  string(n, '.'));
    }
    void findSolutions() {
        solve(0);
        cout << "Total solutions found: " << solutionCount << "\n";
    }
};
int main() {
    int n = 4;
    cout << "Starting N-Queens Solver for N = " << n << "\n";
    NQueensSolver solver(n);
    solver.findSolutions();
    return 0;
}