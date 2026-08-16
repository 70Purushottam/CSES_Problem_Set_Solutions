#include <bits/stdc++.h>
# define ll long long
using namespace std;
 
int main() {
	// your code goes here
int n,m,q;
cin>>n>>m>>q;
vector<vector<ll>> dist(n+1, vector<ll>(n+1, 1e16)); 
 
 
for(int i = 0; i < m; i++){
    int a,b;
    ll c;
    cin>>a>>b;
    cin>>c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
}
for(int k = 1; k <= n; k++){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
             if(dist[i][k] != 1e16 && dist[k][j] != 1e16){
                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
             }
         }
     }
  }
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
          if(dist[i][j] == 1e16) dist[i][j] = -1;
          dist[i][i] = 0;
      }
  }
for(int i = 1; i<=q; i++){
    int a,b;
    cin>>a>>b;
    cout<<dist[a][b]<<"\n";
}
}
