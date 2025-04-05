#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Dinic {
    struct Edge {
        int to, rev;
        int flow, cap;
    };

    int V;
    vector<int> level;
    vector<vector<Edge>> adj;

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (Edge &e : adj[u]) {
                if (level[e.to] < 0 && e.flow < e.cap) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int u, int t, int flow) {
        if (u == t) return flow;
        for (Edge &e : adj[u]) {
            if (level[e.to] == level[u] + 1 && e.flow < e.cap) {
                int f = min(flow, e.cap - e.flow);
                int pushed = dfs(e.to, t, f);
                if (pushed > 0) {
                    e.flow += pushed;
                    adj[e.to][e.rev].flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

public:
    Dinic(int n) : V(n), level(n), adj(n) {}

    void addEdge(int u, int v, int cap) {
        Edge a{v, (int)adj[v].size(), 0, cap};
        Edge b{u, (int)adj[u].size(), 0, 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    int maxFlow(int s, int t) {
        int total = 0;
        while (bfs(s, t)) {
            while (int flow = dfs(s, t, INT_MAX))
                total += flow;
        }
        return total;
    }
};

int main() {
    Dinic dinic(6);
    dinic.addEdge(0, 1, 16);
    dinic.addEdge(0, 2, 13);
    dinic.addEdge(1, 2, 10);
    dinic.addEdge(1, 3, 12);
    dinic.addEdge(2, 1, 4);
    dinic.addEdge(2, 4, 14);
    dinic.addEdge(3, 2, 9);
    dinic.addEdge(3, 5, 20);
    dinic.addEdge(4, 3, 7);
    dinic.addEdge(4, 5, 4);

    cout << "Fluxo máximo: " << dinic.maxFlow(0, 5) << endl;
    return 0;
}