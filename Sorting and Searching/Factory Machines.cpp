// C++ Solution

// Topics : Binary search

#include <bits/stdc++.h>
using namespace std;
# define ll long long
 
bool check(vector<ll>& v,ll t, ll mid){
    ll cnt=0;
    for(int i=0;i<v.size();i++){
        cnt += (mid)/v[i];
        if(cnt>=t)  return 1;
    }
    return 0;
}
 
 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
ll n,t;
cin>>n>>t;
vector<ll> v;
 
for(int i=1;i<=n;i++){
   ll x;
   cin>>x;
   v.push_back(x);
}
 
ll lo=1,hi=1e18,ans=0;
while(lo<=hi){
    ll mid=lo+(hi-lo)/2;
    if(check(v,t,mid)) {ans=mid;hi=mid-1;}
    else lo=mid+1;
}
 cout<<ans<<"\n";
}