// C++ Solution

#include <bits/stdc++.h>
using namespace std;
int ans;
int dfs(vector<int> adj[], int root, vector<bool>& vis){
    
    if(adj[root].size() == 0) return 0;
   // int ans = -1;
   vis[root] = 1;
    int max1 = -1, max2 = -1;
    for(auto it : adj[root]){
        if(vis[it]==1) continue;
        int dis = 1 + dfs(adj, it,vis);
        if(max1 == -1) max1 = dis;
        else if(max2 == -1) {max2 = min(dis,max1);max1=max(max1,dis);}
        else if(max1 <= dis) {max2 = max1;max1=dis;}
        else if(max1 > dis && max2 < dis) max2 = dis;
        if(max1>-1 && max2 > -1) ans = max(ans, max1+max2);  
        else if(max1>-1) ans=max(ans, max1);
    }
  if(max1!=-1)  return max1;
  return 0;
}
 
int main() {
	// your code goes here
int n;
cin>>n;
if(n<=1) {cout<<0<<"\n";return 0;}
ans =-1;
vector<int> adj[n+1];
int st=0;
vector<bool> vis(n+1,0);
for(int i=0;i<n;i++){
    int x, y;
    cin>>x>>y;
    if(st==0) st = x;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
dfs(adj, st,vis);
if(st!=0) cout<<ans;
else cout<<0<<"\n";
 
}