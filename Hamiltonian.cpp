#include <iostream>
using namespace std;
const int MAX_V = 10;
int path[MAX_V];

void printSolution(int V) {
    cout << "Hamiltonian Cycle Found: ";
    for (int i = 0; i < V; i++) {
        cout << path[i] << " -> ";
    }
    cout << path[0] << "\n";
}

bool isSafe(int v, int graph[MAX_V][MAX_V], int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool solveHamiltonian(int graph[MAX_V][MAX_V], int V, int pos) {

    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution(V);
            return true;
        }
        return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, pos)) {
            path[pos] = v;
            if (solveHamiltonian(graph, V, pos + 1)) {
                return true; 
            }

            path[pos] = -1;
        }
    }

    return false;
}

int main() {
    int V = 5;
    int graph[MAX_V][MAX_V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0;
    
    if (!solveHamiltonian(graph, V, 1)) {
        cout << "No Hamiltonian Cycle exists for this graph.\n";
    }

    return 0;
}
