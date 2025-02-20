#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({1, {a, b}});  // All given edges have weight 1
    }

    sort(edges.begin(), edges.end()); // Sorting edges by weight (not necessary here, but good practice)

    DSU dsu(n);
    int mst_weight = 0, count = 0;

    for (auto edge : edges) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mst_weight += w;
            count++;
        }

        if (count == n - 1) // Minimum Spanning Tree should have exactly (n-1) edges
            break;
    }

    cout << mst_weight << endl;
    return 0;
}
