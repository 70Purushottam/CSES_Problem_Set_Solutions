// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int mod=1e9+7;
int n;
int main() {
ios_base::sync_with_stdio(false); 
cin.tie(nullptr);
int x;
cin>>n>>x;
 
vector<int> v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
vector<vector<int>> dp(n+1,vector<int>(x+1));
for(int i=0;i<n;i++){
    dp[i][0]=1;
}
    //dp[0]=1;
    for(int i=n-1;i>=0;i--){
       for(int j=1;j<=x;j++){
           // skipping
           int skip=dp[i+1][j];
           // picking
           int pick=0;
           
           if(v[i] <= j){
               pick=dp[i][j-v[i]];
           }
           dp[i][j]=(skip+pick)%mod;
        }
    }
cout<<dp[0][x];
}