#include <iostream>
using namespace std;

const int MAX = 10;
int n = 5;

int plans = 0;
int path[MAX];

bool checkSlot[MAX];
bool checkDiag1[2 * MAX]; 
bool checkDiag2[2 * MAX]; 

void printPlan() {
    plans++;
    cout << "Plan #" << plans << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "  Res " << i << " -> Slot " << path[i] << "\n";
    }
    cout << "\n";
}

void solve(int res) {
    if (res == n) {
        printPlan();
        return;
    }

    for (int slot = 0; slot < n; slot++) {
        
        int d1 = res - slot + (n - 1);
        int d2 = res + slot;

        if (!checkSlot[slot] && !checkDiag1[d1] && !checkDiag2[d2]) {
            
            path[res] = slot;
            checkSlot[slot] = true;
            checkDiag1[d1] = true;
            checkDiag2[d2] = true;

            solve(res + 1);

            checkSlot[slot] = false;
            checkDiag1[d1] = false;
            checkDiag2[d2] = false;
        }
    }
}

int main() {
    for (int i = 0; i < MAX; i++) {
        checkSlot[i] = false;
    }
    for (int i = 0; i < 2 * MAX; i++) {
        checkDiag1[i] = false;
        checkDiag2[i] = false;
    }

    cout << "Calculating resource plans for N = " << n << "...\n\n";
    
    solve(0); 

    cout << "Total plans found: " << plans << "\n";
    return 0;
}
