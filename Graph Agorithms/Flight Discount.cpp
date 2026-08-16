// C++ Solution

// Topics : Dijkstra's Algorithm

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pill pair<ll, int> // {distance, node}
 
const ll INF = 1e17;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    if (!(cin >> n >> m)) return 0;
 
    // adj[u] stores pairs of {v, weight}
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    // dist[node][0] = cost without discount
    // dist[node][1] = cost with discount used
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    
    // Min-priority queue storing {cost, {node, discount_used}}
    priority_queue<pair<ll, pair<int, int>>, 
                   vector<pair<ll, pair<int, int>>>, 
                   greater<pair<ll, pair<int, int>>>> pq;
 
    dist[1][0] = 0;
    pq.push({0, {1, 0}});
 
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
 
        ll d = curr.first;
        int u = curr.second.first;
        int used = curr.second.second;
 
        // Skip outdated states
        if (d > dist[u][used]) continue;
 
        for (auto edge : adj[u]) {
            int v = edge.first;
            ll weight = edge.second;
 
            // Option 1: Do not use a discount on this edge
            if (dist[u][used] + weight < dist[v][used]) {
                dist[v][used] = dist[u][used] + weight;
                pq.push({dist[v][used], {v, used}});
            }
 
            // Option 2: Use a discount on this edge (only if we haven't used one yet)
            if (used == 0) {
                if (dist[u][0] + weight / 2 < dist[v][1]) {
                    dist[v][1] = dist[u][0] + weight / 2;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
        }
    }
 
    // The answer is the minimum cost to reach node n with the discount used
    cout << dist[n][1] << "\n";
 
    return 0;
}
