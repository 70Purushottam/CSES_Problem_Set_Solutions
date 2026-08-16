// C++ Solution

// Topics : Bellman Ford Algorithm

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
// Representation of a one-way tunnel
struct Edge {
    int u, v;
    long long w;
};
 
const long long INF = 1e18; // Use a sufficiently large infinity value
 
int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    if (!(cin >> n >> m)) return 0;
 
    vector<Edge> edges(m);
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev_adj(n + 1);
 
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        adj[edges[i].u].push_back(edges[i].v);
        rev_adj[edges[i].v].push_back(edges[i].u);
    }
 
    // 1. BFS from Room 1 to find all reachable rooms
    vector<bool> from_1(n + 1, false);
    queue<int> q;
    from_1[1] = true;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!from_1[v]) {
                from_1[v] = true;
                q.push(v);
            }
        }
    }
 
    // 2. BFS backward from Room n to find rooms that can reach the destination
    vector<bool> to_n(n + 1, false);
    to_n[n] = true;
    q.push(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : rev_adj[u]) {
            if (!to_n[v]) {
                to_n[v] = true;
                q.push(v);
            }
        }
    }
 
    // 3. Modified Bellman-Ford for Maximization
    vector<long long> dist(n + 1, -INF);
    dist[1] = 0;
 
    // Standard relaxation phase (run n - 1 times)
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != -INF && dist[edge.u] + edge.w > dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }
 
    // Positive cycle detection phase (run n more times)
    for (int i = 0; i < n; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != -INF && dist[edge.u] + edge.w > dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                // If this room can create an infinite loop affecting Room n
                if (from_1[edge.v] && to_n[edge.v]) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
 
    cout << dist[n] << "\n";
    return 0;
}
