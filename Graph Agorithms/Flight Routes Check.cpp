// C++ Solution
// Forward and Backward dfs
#include <bits/stdc++.h>
using namespace std;
 
void dfs(vector<int> adj[], int node, vector<bool>& vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(adj, it, vis);
    }
    return;
}
 
int main() {
	// your code goes here
int n,m;
cin>>n>>m;
vector<int> adj[n+1], revadj[n+1];
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    revadj[v].push_back(u);
}
vector<bool> vis(n+1,false);
dfs(adj, 1, vis);
for(int i=1;i<=n;i++){
    if(vis[i] == 0) {
        cout<<"NO"<<"\n";
        cout<<1<<" "<<i<<"\n";
        return 0;
    }
}
vis= vector<bool>(n+1, false);
dfs(revadj, 1, vis);
for(int i=1;i<=n;i++){
    if(vis[i] == 0) {
        cout<<"NO"<<"\n";
        cout<<i<<" "<<1<<"\n";
        return 0;
    }
}
cout<<"YES"<<"\n";
}
