#include <iostream>

using namespace std;

const int MAX = 10;
int tasks = 6;
int resources = 4;

int assignment[MAX];

bool graph[MAX][MAX] = {
    {0, 1, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 0}
};

bool isSafe(int t, int r) {
    for (int i = 0; i < tasks; i++) {
        if (graph[t][i] && assignment[i] == r) {
            return false;
        }
    }
    return true;
}

bool solve(int t) {
    // Base Case: All tasks assigned successfully
    if (t == tasks) return true;

    // Try assigning every resource (1 to 4)
    for (int r = 1; r <= resources; r++) {
        if (isSafe(t, r)) {
            
            assignment[t] = r; // Assign resource

            if (solve(t + 1)) return true; // Move to next task

            assignment[t] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < tasks; i++) {
        assignment[i] = 0;
    }

    if (solve(0)) {
        cout << "Valid Resource Allocation Matrix:\n";
        for (int i = 0; i < tasks; i++) {
            cout << "  Task " << i + 1 << " -> Assigned to Resource " << assignment[i] << "\n";
        }
    } else {
        cout << "No valid allocation plan possible with " << resources << " resources.\n";
    }
    return 0;
}
