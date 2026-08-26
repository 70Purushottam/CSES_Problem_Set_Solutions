// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
ll Root_res;
vector<int> Nodecount;
 
int dfsBase(vector<int> adj[], int curr_node, int prev_node, int curr_depth){
   int totalnode = 1;
   Root_res += curr_depth;
   for(auto it : adj[curr_node]){
    if(it == prev_node) continue;
       totalnode += dfsBase(adj, it, curr_node, curr_depth+1);
   }
   Nodecount[curr_node] = totalnode;
   return totalnode;
}
 
void DFS(vector<int> adj[], int curr_node, int prev_node, vector<ll>& result, int n){
   for(auto it : adj[curr_node]){
    if(it == prev_node) continue;
    result[it] = result[curr_node] - (ll)Nodecount[it] + (ll)(n - Nodecount[it]);
    DFS(adj, it, curr_node, result, n);
   }
}
 
int main() {
	// your code goes here
int n;
cin>>n;
vector<int> adj[n+1];
int st  =-1;
for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    if(st==-1) st = u;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
      Root_res  = 0;
      Nodecount.resize(n+1,0);
      dfsBase(adj, 1, -1, 0);
      vector<ll> result(n+1,0);
      result[1] = Root_res;
      DFS(adj, 1, -1, result, n);
   for(int i=1;i<=n;i++) cout<<result[i]<<" ";
}