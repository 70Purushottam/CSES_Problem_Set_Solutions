// C++ Solution

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MAXN=2E5+1;
vector<ll>g[MAXN];
vector<ll>dis(MAXN,0);
 
void dfs(int node,int par){
    for(auto &c:g[node]){
        if(c != par){
            dis[c]=dis[node]+1;
            dfs(c,node);
        }
    }
}
 
void _144()
{
    ll n;
    cin>>n;
 
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
 
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(1,-1);
 
    ll firstFarthestNode=-1;
    ll maxi=0;
    for(int i=1;i<=n;i++){
        if(dis[i]>maxi){
            maxi=dis[i];
            firstFarthestNode=i;
        }
    }
 
    dis.assign(n+1,0);
    dfs(firstFarthestNode,-1);
 
    maxi=0;
    ll secondFarthestNode=-1;
 
    for(int i=1;i<=n;i++){
        if(dis[i]>maxi){
            maxi=dis[i];
            secondFarthestNode=i;
        }
    }
 
    vector<ll>distFromFirst=dis;
    
    dis.assign(n+1,0);
    dfs(secondFarthestNode,-1);
 
    vector<ll>distFromSecond=dis;
 
    for(int i=1;i<=n;i++) cout<<max(distFromFirst[i],distFromSecond[i])<<" ";
    return;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t=1;
    // cin >> t;
 
    while (t--) _144();
    return 0;
}