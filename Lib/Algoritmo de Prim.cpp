#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> iPair;

class Prim {
    int V;
    vector<vector<iPair>> adj;

public:
    Prim(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<Edge> findMST() {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        int src = 0;
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        pq.push({0, src});
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto &[v, weight] : adj[u]) {
                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        vector<Edge> result;
        for (int i = 1; i < V; ++i)
            result.push_back({parent[i], i, key[i]});
        return result;
    }
};

int main() {
    Prim p(4);
    p.addEdge(0, 1, 10);
    p.addEdge(0, 2, 6);
    p.addEdge(0, 3, 5);
    p.addEdge(1, 3, 15);
    p.addEdge(2, 3, 4);

    vector<Edge> mst = p.findMST();
    cout << "Arestas na MST:" << endl;
    for (Edge e : mst)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    return 0;
}