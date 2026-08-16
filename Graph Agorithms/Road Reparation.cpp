// C++ Solution

# include <bits/stdc++.h>
# define ll long long
using namespace std;
 
typedef pair<ll,int> pill;
typedef pair<int, ll> pil;
 
int main() {
	// your code goes here
int n,m;
cin>>n>>m;
vector<pil> adj[n+1];
for(int i=0;i<m;i++){
    int a,b;
    ll c;
    cin>>a>>b;
    cin>>c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
}
 
priority_queue<pill, vector<pill>, greater<pill>> pq; // min heap
 
vector<ll> vertex(n+1, 1e16);
vector<bool> vis(n+1,0);
 
//vector<int> parent(n+1,0);
 
pq.push({0,1});
 
vertex[1] = 0;
ll totalwt = 0;
 
while(!pq.empty()){
    int node = pq.top().second;
    ll val = pq.top().first;
    
    pq.pop();
    
    if(vis[node]) continue;
    
    totalwt += val;
    vis[node] = 1;
    
    for(auto it : adj[node]){
        int neigh = it.first;
        ll x = it.second;
        if(!vis[neigh] && vertex[neigh] > x){
          //  parent[neigh] = node;
            vertex[neigh] = x;
            pq.push({x, neigh});
           }
       }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) cnt++;
    }
    if(cnt != n)  {cout<<"IMPOSSIBLE";
        return 0;}
    cout<<totalwt<<"\n";
}
