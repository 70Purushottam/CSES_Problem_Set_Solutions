// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
int calculate_subordinates(int node, const vector<vector<int>>& adj, vector<int>& subordinates) {
    int total_subordinates = 0;
    
    for (int child : adj[node]) {
        total_subordinates += 1 + calculate_subordinates(child, adj, subordinates);
    }
    
    subordinates[node] = total_subordinates;
    return total_subordinates;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<vector<int>> adj(n + 1);
    
    // Read the boss for employee 2, 3, ..., n
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i); 
    
    vector<int> subordinates(n + 1, 0);
    
    calculate_subordinates(1, adj, subordinates);
    
    for (int i = 1; i <= n; i++) {
        cout << subordinates[i] << (i == n ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}