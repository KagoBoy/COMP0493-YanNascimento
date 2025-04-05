#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

class Kruskal {
    int n;
    vector<Edge> edges;

public:
    Kruskal(int size) : n(size) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    vector<Edge> findMST() {
        vector<Edge> result;
        UnionFind uf(n);
        sort(edges.begin(), edges.end());

        for (Edge e : edges) {
            if (uf.find(e.u) != uf.find(e.v)) {
                result.push_back(e);
                uf.unionSets(e.u, e.v);
            }
        }
        return result;
    }
};

int main() {
    Kruskal k(4);
    k.addEdge(0, 1, 10);
    k.addEdge(0, 2, 6);
    k.addEdge(0, 3, 5);
    k.addEdge(1, 3, 15);
    k.addEdge(2, 3, 4);

    vector<Edge> mst = k.findMST();
    cout << "Arestas na MST:" << endl;
    for (Edge e : mst)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    return 0;
}