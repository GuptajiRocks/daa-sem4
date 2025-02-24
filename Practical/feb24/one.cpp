#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [current_dist, u] = pq.top();
        pq.pop();
        if(current_dist > dist[u]) continue;

        for(auto &edge : graph[u]){
            int v = edge.first;
            long long w = edge.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest-distances-from-the-central-distribution-center (source vertex 0) to all-other-locations:\n";
    for(int i = 0; i < n; i++){
        if(dist[i] == LLONG_MAX)
            cout << "Location " << i << ": unreachable\n";
        else
            cout << "Location " << i << ": " << dist[i] << " units\n";
    }

    return 0;
}
