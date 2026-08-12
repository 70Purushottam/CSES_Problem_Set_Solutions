// C++ Solution

// Topics : BFS

#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int node, vector<bool>& vis){
    
    queue<int> q;
    
    q.push(node);
    
    while(!q.empty()){
     int x = q.front();
     vis[x] = 1;
     q.pop();
     for(auto it : adj[x]){
         if(vis[it]==0) q.push(it);
     }
    }
    
}
int main() {
	// your code goes here
int n,m;
cin>>n>>m;
vector<int> adj[n+1];
if(n==1) {cout<<0<<"\n";
return 0;}
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
 
vector<bool> vis(n+1, 0);
vector<pair<int,int>> ans;
for(int i=1;i<=n;i++){
    if(vis[i] == 0){
    
          if(i==1) bfs(adj, i, vis);
          else {ans.push_back({i, i-1});
              bfs(adj, i, vis);
          }
      }
}
int  sz = ans.size();
cout<<sz<<"\n";
for(int i=0;i<sz; i++){
    cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}
}


