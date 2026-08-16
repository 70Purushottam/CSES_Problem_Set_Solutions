// C++ Solution

// Topics : Dfs + Dp

#include <bits/stdc++.h>
using namespace std;
# define ll long long
ll mod = 1e9+7;
vector<ll> dp;
int dfs(vector<int> adj[], vector<bool>& vis, int node, int n){
    if(node == n) return 1;
    if(dp[node] != -1) return dp[node];
    vis[node] = 1;
    ll ans = 0;
    for(auto it : adj[node]){
        if(vis[it] == 0) {
            ans += dfs(adj, vis, it, n);
            ans %= mod;
        }
    }
    vis[node] = 0;
    return dp[node] = ans;
}
int main() {
	// your code goes here
int n,m;
cin>>n>>m;
vector<int> adj[n+1];
for(int i= 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
}
dp.resize(n+1,-1);
vector<bool> vis(n+1,0);
cout<<dfs(adj, vis, 1, n );
}
