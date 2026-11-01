#include <iostream>
using namespace std;

const int N = 4;
const int INF = 999999;

int matrix[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

bool visited[N];
int finalPath[N + 1];
int finalCost = INF;

int getMinEdge(int city) {
    int minEdge = INF;
    for (int i = 0; i < N; i++) {
        if (matrix[city][i] < minEdge && city != i) {
            minEdge = matrix[city][i];
        }
    }
    return minEdge;
}

int estimateRemainingCost() {
    int estimate = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            estimate += getMinEdge(i); 
        }
    }
    return estimate;
}

void solveTSP(int currentCity, int currentCost, int level, int currentPath[]) {
    if (level == N) {
        int totalCost = currentCost + matrix[currentCity][0]; 
        if (totalCost < finalCost) {
            finalCost = totalCost;
            for (int i = 0; i < N; i++) finalPath[i] = currentPath[i];
            finalPath[N] = 0; 
        }
        return;
    }

    for (int nextCity = 0; nextCity < N; nextCity++) {
        if (!visited[nextCity] && matrix[currentCity][nextCity] != 0) {
            
            int nextCost = currentCost + matrix[currentCity][nextCity];
            int predictedCost = nextCost + estimateRemainingCost();

            if (predictedCost < finalCost) {
                currentPath[level] = nextCity;
                visited[nextCity] = true;
                solveTSP(nextCity, nextCost, level + 1, currentPath);

                visited[nextCity] = false;
            }
        }
    }
}

int main() {
    int currentPath[N + 1];
    for (int i = 0; i < N; i++) visited[i] = false;

    // Start at City 0
    visited[0] = true;
    currentPath[0] = 0;

    cout << "Running Simple TSP Branch and Bound...\n\n";
    solveTSP(0, 0, 1, currentPath);
    cout << "Minimum Cost: " << finalCost << "\n";
    cout << "Route Taken: ";
    for (int i = 0; i <= N; i++) {
        cout << finalPath[i] << (i < N ? " -> " : "\n");
    }

    return 0;
}
