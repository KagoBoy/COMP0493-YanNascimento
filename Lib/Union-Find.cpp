#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent, rank;
    int n;

public:
    UnionFind(int size) : n(size), parent(size), rank(size, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return;

        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootU] = rootV;
            if (rank[rootU] == rank[rootV])
                rank[rootV]++;
        }
    }
};

int main() {
    UnionFind uf(5);
    uf.unionSets(0, 2);
    uf.unionSets(4, 2);
    uf.unionSets(3, 1);

    cout << "1 e 3 no mesmo conjunto? " << (uf.find(1) == uf.find(3)) << endl;
    cout << "0 e 4 no mesmo conjunto? " << (uf.find(0) == uf.find(4)) << endl;
    cout << "1 e 4 no mesmo conjunto? " << (uf.find(1) == uf.find(4)) << endl;
    return 0;
}