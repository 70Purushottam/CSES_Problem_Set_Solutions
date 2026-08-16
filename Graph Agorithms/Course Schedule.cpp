// C++ Solution

// Topics : Topological Sorting

# include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
    queue<int> q;
    vector<int> indegree(n+1,0);
    vector<int> ans;
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
        indegree[a]++;
    }
    for(int i = 1; i<=n;i++){
        if(indegree[i] == 0) q.push(i); 
    }
  while(!q.empty()){
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for(auto it : adj[node]){
          indegree[it]--;
          if(indegree[it] == 0) q.push(it);
      }
  }
  for(int i=1;i<=n;i++) {
      if(indegree[i]>0) {
          cout<<"IMPOSSIBLE"<<"\n";
          return 0;
      }
  }
  
  for(int i=0;i<n;i++){
      cout<<ans[n-1-i]<<" ";
  }
}
