#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int n, m;
    vector<vector<int>> adj; // 2D adjacency matrix

public:
    Graph(int vertices, int edges) {
        n = vertices;
        m = edges;
        adj.assign(n + 1, vector<int>(n + 1, 0)); // Initialize with weight 0
    }

    void addEdge(int u, int v, int weight) {
        adj[u][v] = weight;
        adj[v][u] = weight;
    }

    void buildCompleteGraph() {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (adj[i][j] == 0) addEdge(i, j, 0);
            }
        }
    }

    int primMST() {
        vector<int> key(n + 1, 1e9); // Stores minimum edge weight
        vector<bool> visited(n + 1, false); // Tracks visited nodes
        int mstWeight = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1}); // Start from node 1
        key[1] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;

            visited[u] = true;
            mstWeight += key[u];

            for (int v = 1; v <= n; v++) {
                if (!visited[v] && adj[u][v] > 0 && adj[u][v] < key[v]) {
                    key[v] = adj[u][v];
                    pq.push({key[v], v});
                }
            }
        }

        return mstWeight;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b, 1);
    }

    graph.buildCompleteGraph();

    cout << "Minimum Spanning Tree Weight: " << graph.primMST() << endl;

    return 0;
}