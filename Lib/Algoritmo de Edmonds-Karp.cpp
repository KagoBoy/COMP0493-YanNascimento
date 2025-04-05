#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class EdmondsKarp {
    int V;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;

    int bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INT_MAX});

        while (!q.empty()) {
            int u = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v]) {
                    parent[v] = u;
                    int new_flow = min(flow, capacity[u][v]);
                    if (v == t)
                        return new_flow;
                    q.push({v, new_flow});
                }
            }
        }
        return 0;
    }

public:
    EdmondsKarp(int n) : V(n), capacity(n, vector<int>(n, 0)), adj(n) {}

    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        vector<int> parent(V);
        int new_flow;

        while (new_flow = bfs(s, t, parent)) {
            flow += new_flow;
            int v = t;
            while (v != s) {
                int u = parent[v];
                capacity[u][v] -= new_flow;
                capacity[v][u] += new_flow;
                v = u;
            }
        }
        return flow;
    }
};

int main() {
    EdmondsKarp ek(6);
    ek.addEdge(0, 1, 16);
    ek.addEdge(0, 2, 13);
    ek.addEdge(1, 2, 10);
    ek.addEdge(1, 3, 12);
    ek.addEdge(2, 1, 4);
    ek.addEdge(2, 4, 14);
    ek.addEdge(3, 2, 9);
    ek.addEdge(3, 5, 20);
    ek.addEdge(4, 3, 7);
    ek.addEdge(4, 5, 4);

    cout << "Fluxo máximo: " << ek.maxFlow(0, 5) << endl;
    return 0;
}