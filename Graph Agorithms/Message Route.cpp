// C++ Solution

//Topics : BFS


#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int src, int dst) {
    vector<int> parent(dst+1, -1);
    queue<pair<int,int>> q;
 
    q.push({0,src});
    
    while(!q.empty()){
        
     int val = q.front().first;
     int node = q.front().second;
     
     parent[src] = -2;
     q.pop();
     
     if(node == dst) {
         cout<<val+1<<"\n";
     int x = dst;
     vector<int> ans;
     ans.push_back(dst);
     while(x!=src){
         x = parent[x];
          ans.push_back(x);
     }
     int sz = ans.size();
     for(int i=sz-1;i>=0;i--){
         cout<<ans[i]<<" ";
     }
     return;}
     
     for(auto it : adj[node]){
           if(parent[it] == -1){  parent[it] = node;
             q.push({1+val, it});
           }
     }
    }
    cout<<"IMPOSSIBLE"<<"\n";
}
int main() {
	// your code goes here
int n,m;
cin>>n>>m;
vector<int> adj[n+1];
 
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
 
bfs(adj, 1, n);
}