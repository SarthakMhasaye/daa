#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) { parent[root_i] = root_j; return true; }
        return false;
    }
};

int main() {
    int V = 5; // 5 Neighborhoods (0 to 4)
    vector<Edge> edges = {
        {0, 1, 9}, {0, 2, 75}, {0, 3, 18}, {0, 4, 15},
        {1, 2, 95}, {1, 3, 42}, {1, 4, 25},
        {2, 3, 51}, {2, 4, 60},
        {3, 4, 12}
    };

    sort(edges.begin(), edges.end());

    DSU dsu(V);
    int mstWeight = 0;

    cout << "Optimized Road Network Construction:\n";
    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            cout << "Build road between N" << edge.u << " and N" << edge.v
                      << " (Length: " << edge.weight << ")\n";
        }
    }
    cout << "\nMinimum Total Road Length: " << mstWeight << "\n";
    return 0;
}
