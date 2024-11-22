#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Define the structure for an edge
class Edge {
    public:
int u, v, weight;
bool operator<(const Edge& lhs, const Edge& rhs) {
    return lhs.weight < rhs.weight;
}

};
// Union-Find structure with path compression and union by rank
class UnionFind {
public:
vector<int> parent, rank;
UnionFind(int n) {
parent.resize(n);
rank.resize(n, 0);
for (int i = 0; i < n; ++i) parent[i] = i;
}
int find(int u) {
if (u != parent[u])
parent[u] = find(parent[u]); // Path compression
return parent[u];
}
void unionSets(int u, int v) {
u = find(u);
v = find(v);
if (u != v) {
if (rank[u] < rank[v])
swap(u, v);
parent[v] = u;
if (rank[u] == rank[v])
rank[u]++;
}
}
};
// Kruskal's algorithm to find the MST
int kruskal(int n, vector<Edge>& edges, vector<Edge>& mst) {
sort(edges.begin(), edges.end()); // Sort edges by weight
UnionFind uf(n);
int mincost = 0;
for (const Edge& edge : edges) {
if (uf.find(edge.u) != uf.find(edge.v)) { // Check if u and v are in different sets
uf.unionSets(edge.u, edge.v); // Union the sets
mst.push_back(edge); // Add edge to MST
mincost += edge.weight;
if (mst.size() == n - 1) // Stop if we have n-1 edges in MST
break;
}
}
// If MST has less than n-1 edges, no spanning tree exists
if (mst.size() != n - 1)
return -1; // No spanning tree
return mincost;
}
int main() {
int n, m;
cout << "Enter the number of vertices and edges: ";
cin >> n >> m;
vector<Edge> edges(m);
cout << "Enter each edge (u, v, weight):" << endl;
for (int i = 0; i < m; ++i) {
cin >> edges[i].u >> edges[i].v >> edges[i].weight;
}
vector<Edge> mst;
int mincost = kruskal(n, edges, mst);
if (mincost == -1) {
cout << "No spanning tree exists." << endl;
} else {
cout << "Minimum cost of the spanning tree: " << mincost << endl;
cout << "Edges in the MST:" <<endl;
for (const Edge& edge : mst) {
cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
}
}
return 0;
}