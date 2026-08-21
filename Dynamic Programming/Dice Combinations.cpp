// C++ Solution

# include <bits/stdc++.h>
using namespace std;
# define ll long long
ll mod=1e9+7;
ll dp[1000001];
ll func(ll n){
   if(n<0) return 0;
   if(n==0) return 1;
   if(dp[n]!=-1) return dp[n];
   ll sum=0;
   for(int i=1;i<=6;i++){
       sum += func(n-i);
       sum %=mod;
   }
   return dp[n]=sum%mod;
}
 
 
int main() {
	// your code goes here
ll n;
cin>>n;
memset(dp,-1,sizeof(dp));
cout<<func(n);
}