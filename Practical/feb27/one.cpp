#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
void printPath(vector<int> &parent, int vertex) { if (vertex == -1) return; printPath(parent, parent[vertex]); if (parent[vertex] != -1) cout << " -> "; cout << vertex; }
void dijkstra(vector<vector<int>> &graph, int source, int V) { vector<int> dist(V, INF); vector<int> parent(V, -1); vector<bool> visited(V, false); dist[source] = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push({0, source});
while (!pq.empty()) { int u = pq.top().second; pq.pop(); if (visited[u]) continue; visited[u] = true;
for (int v = 0; v < V; v++) { if (graph[u][v] > 0 && !visited[v]) { int newDist = dist[u] + graph[u][v]; if (newDist < dist[v]) { dist[v] = newDist; parent[v] = u; pq.push({dist[v], v}); } } } }
cout << "Vertex   Distance   Path\n";
for (int i = 0; i < V; i++) { 
cout << i << "        " << (dist[i] == INF ? "INF" : to_string(dist[i])) << "        ";
if (dist[i] == INF) cout << 5; else printPath(parent, i); cout << "\n"; } }
int main() { int V; cin >> V; vector<vector<int>> graph(V, vector<int>(V)); for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) cin >> graph[i][j]; int source; cin >> source; dijkstra(graph, source, V); return 0; }
