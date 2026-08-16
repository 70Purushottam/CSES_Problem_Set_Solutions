#include <bits/stdc++.h>
# define ll long long
using namespace std;
 
int main() {
	// your code goes here
int n,m;
cin>>n>>m;
vector<pair<int,ll>> adj[n+1];
 
for(int i = 0; i < m; i++){
    int a,b;
    ll c;
    cin>>a>>b;
    cin>>c;
    adj[a].push_back({b,c});
}
 
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
pq.push({0,1});
vector<ll> dist(n+1, 1e16);
 
dist[1] = 0;
 
while(!pq.empty()){
    ll val = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if(dist[node] < val) continue;
    for(auto it : adj[node]){
        ll x = it.second;
        int neighbour = it.first;
        
        if(dist[neighbour] > x + dist[node]){ dist[neighbour] = x + dist[node];
        pq.push({dist[neighbour] ,neighbour});}
    }
}
for(int i=1;i<=n;i++){
    cout<<dist[i]<<" ";
}
}
