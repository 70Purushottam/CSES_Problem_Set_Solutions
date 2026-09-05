// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
vector<int> subTree;
int cnt;
void dfs(vector<int> adj[], int node, vector<bool>& vis, int par){
    
      for(auto it: adj[node]){
        if(it != par)  {
            dfs(adj, it, vis, node);
            if(!vis[node] && !vis[it]) {
              cnt++;
              vis[node] = vis[it] = 1;
           }
            
         }
      }
}
 
int main() {
	// your code goes here
int n;
cin>>n;
vector<int> adj[n+1];
for(int i=2;i<=n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
vector<bool> vis(n+1, 0);
 
cnt = 0;
 
dfs(adj, 1, vis, -1);
 
cout<<cnt<<"\n";
}

