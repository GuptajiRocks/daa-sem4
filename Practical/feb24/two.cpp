//deliveryrouting

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

class DeliveryRouter {
private:
int V; // Number of vertices (locations)
std::vector<std::vector<std::pair<int, int>>> adj; // Adjacency list

public:
DeliveryRouter(int vertices) : V(vertices) {
adj.resize(vertices);
}

// Add an edge (road) between two locations
void addEdge(int source, int dest, int weight) {
adj[source].push_back({dest, weight});
adj[dest].push_back({source, weight}); // Since roads are bidirectional
}

// Find shortest paths using Dijkstra's algorithm
std::vector<int> findShortestPaths(int source) {
// Priority queue to store vertices and their distances
std::priority_queue<std::pair<int, int>,
std::vector<std::pair<int, int>>,
std::greater<std::pair<int, int>>> pq;

// Vector to store distances to all vertices
std::vector<int> dist(V, std::numeric_limits<int>::max());

// Distance to source vertex is 0
dist[source] = 0;
pq.push({0, source});

while (!pq.empty()) {
int u = pq.top().second;
pq.pop();

// For each adjacent vertex
for (const auto& neighbor : adj[u]) {
int v = neighbor.first;
int weight = neighbor.second;

// If we found a shorter path
if (dist[v] > dist[u] + weight) {
dist[v] = dist[u] + weight;
pq.push({dist[v], v});
}
}
}

return dist;
}
};

int main() {
int V, E; // V = number of vertices, E = number of edges
std::cout << "Enter the number of locations and roads: ";
std::cin >> V >> E;

DeliveryRouter router(V);

std::cout << "Enter the source vertex and edges (source destination weight) for each road:" << std::endl;
int source;
std::cin >> source; // Read source vertex

// Read edges
for (int i = 0; i < E; i++) {
int src, dest, weight;
std::cin >> src >> dest >> weight;
router.addEdge(src, dest, weight);
}

// Find shortest paths from source
std::vector<int> shortestDistances = router.findShortestPaths(source);

// Print results
std::cout << "Shortest distances from the central distribution center (source vertex "
<< source << ") to all other locations:" << std::endl;

for (int i = 0; i < V; i++) {
std::cout << "Location " << i << ": " << shortestDistances[i] << " units" << std::endl;
}

return 0;
}