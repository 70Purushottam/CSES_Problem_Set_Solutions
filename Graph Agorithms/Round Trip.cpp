// C++ Solution

// Topics : dfs

# include <bits/stdc++.h>
# define ll long long
using namespace std;
 
bool findCycle(int node, int parentNode, vector<int> adj[], 
               vector<bool>& visited, vector<int>& parent, int& cycleStart, int& cycleEnd) {
    
    visited[node] = true;
 
    for (int neighbor : adj[node]) {
        if (neighbor == parentNode) continue; 
 
        if (visited[neighbor]) {
            cycleStart = neighbor;
            cycleEnd = node;
            return true;
        }
 
        parent[neighbor] = node;
        
        if (findCycle(neighbor, node, adj, visited, parent, cycleStart, cycleEnd)) {
            return true;
        }
    }
    return false;
}
 
void printSingleCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V+1, false);
    vector<int> parent(V+1, -1);
    
    int cycleStart = -1;
    int cycleEnd = -1;
 
    for (int i = 1; i <= V; ++i) {
        if (!visited[i]) {
            if (findCycle(i, -1, adj, visited, parent, cycleStart, cycleEnd)) {
                break;
            }
        }
    }
 
    // if no cycle was tracked
    if (cycleStart == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    // Reconstruct the path backwards from cycleEnd to cycleStart
    vector<int> path;
    int current = cycleEnd;
    
    while (current != cycleStart) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(cycleStart);
 
    // Reverse the path to get chronological order
    reverse(path.begin(), path.end());
   cout<<path.size() + 1<<"\n";
    for (int node : path) {
        cout << node << " ";
    }
    cout << cycleStart << "\n"; // Complete the loop sequence visually
}
 
int main() {
	// your code goes here
int n,m;
cin>>n>>m;
vector<int> adj[n+1];
 
for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
 
printSingleCycle(n,adj);
 
}
