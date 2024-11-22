#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
struct Vertex {
int d; // shortest-path estimate
int pi; // predecessor
};
struct Edge {
int v; // destination vertex
int weight; // weight of the edge
};
// Comparator for priority queue to find the minimum distance vertex
struct CompareDist {
bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
return p1.second > p2.second;
}
};
// Initialize the single source
void InitializeSingleSource(vector<Vertex>& vertices, int s) {
for (int i = 0; i < vertices.size(); i++) {
vertices[i].d = INT_MAX; // Set initial distance to "infinity"
vertices[i].pi = -1; // Set predecessor to NIL (or -1 here)
}
vertices[s].d = 0; // Distance to the source itself is 0
}
// Relaxation function
void Relax(int u, int v, int w, vector<Vertex>& vertices) {
if (vertices[v].d > vertices[u].d + w) {
vertices[v].d = vertices[u].d + w;
vertices[v].pi = u;
}
}
// Dijkstra's Algorithm
void Dijkstra(vector<vector<Edge>>& adjList, vector<Vertex>& vertices, int source) {
InitializeSingleSource(vertices, source);
priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDist> minHeap;
minHeap.push({source, vertices[source].d});
while (!minHeap.empty()) {
int u = minHeap.top().first;
minHeap.pop();
for (auto& edge : adjList[u]) {
int v = edge.v;
int weight = edge.weight;
if (vertices[v].d > vertices[u].d + weight) {
vertices[v].d = vertices[u].d + weight;
vertices[v].pi = u;
minHeap.push({v, vertices[v].d});
}
}
}
}
int main() {
    int numVertices = 5;
vector<Vertex> vertices(numVertices);
// Adjacency list for the graph (directed graph with nonnegative weights)
vector<vector<Edge>> adjList(numVertices);
// Add edges based on the input graph
adjList[0].push_back({1, 10});
adjList[0].push_back({3, 5});
adjList[1].push_back({2, 1});
adjList[1].push_back({3, 2});
adjList[3].push_back({1, 3});
adjList[3].push_back({2, 9});
adjList[3].push_back({4, 2});
adjList[2].push_back({4, 4});
adjList[4].push_back({2, 6});
adjList[4].push_back({0, 7});
int source = 0; // Starting from vertex 's'
Dijkstra(adjList, vertices, source);
// Output the shortest-path estimates and predecessors
cout << "Vertex\tShortest Path Estimate (d)\tPredecessor (pi)" << endl;
for (int i = 0; i < vertices.size(); i++) {
cout << i << "\t" << vertices[i].d << "\t\t\t\t" << (vertices[i].pi == -1 ? "NIL" :
to_string(vertices[i].pi)) << endl;
}
return 0;
}