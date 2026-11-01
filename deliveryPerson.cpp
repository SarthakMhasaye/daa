#include <iostream>
using namespace std;

const int MAX = 10;
int n = 6;

int path[MAX];
bool vis[MAX];

bool graph[MAX][MAX] = {
    {0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0},
    {1, 1, 0, 1, 0, 1},
    {0, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0}
};
void printPath() {
    for (int i = 0; i < n; i++) {
        cout << path[i] + 1 << " -> ";
    }
    cout << path[0] + 1 << "\n"; 
}

bool solve(int pos) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]]) {
            printPath();
            return true;
        }
        return false;
    }

    bool found = false;
    for (int v = 1; v < n; v++) {

        if (!vis[v] && graph[path[pos - 1]][v]) {
            
            path[pos] = v;   
            vis[v] = true;   

            if (solve(pos + 1)) {
                found = true;
            }

            vis[v] = false;
        }
    }

    return found;
}
int main() {
    for (int i = 0; i < n; i++) {
        vis[i] = false;
        path[i] = 0;
    }
    path[0] = 0;
    vis[0] = true;

    cout << "Valid Delivery Routes (Hamiltonian Circuits):\n";
    
    if (!solve(1)) {
        cout << "No Hamiltonian Circuit exists.\n";
    }

    return 0;
}
