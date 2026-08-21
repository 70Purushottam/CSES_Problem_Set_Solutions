// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
ll n,x;
cin>>n>>x;
 
vector<ll> v(n+1);
for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    v[i]=x;
}
 
vector<ll> dp(x+1,1e9);
 
//dp[x] -> dp[x-c[i]]
 
// base case
dp[0]=0;
 
for(int i=1;i<=x;i++){
    for(int j=1;j<=n;j++){
        if(v[j] <= i)
        {
            dp[i]=min(dp[i],dp[i-v[j]] + 1);
        }
    }
}
 
cout<<(dp[x] < 1e9 ? dp[x] : -1)<<"\n";
}