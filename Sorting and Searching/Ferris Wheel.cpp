// C++ Solution

// Topics: sorting

#include <bits/stdc++.h>
using namespace std;
# define ll long long
 
int main() {
	// your code goes here
ll n,x;
cin>>n>>x;
 
ll a[n];
 
for(ll i=0;i<n;i++){
    cin>>a[i];
}
 ll ans=0;
 
sort(a,a+n);
 
ll j=0,i=n-1;
// for(ll i=n-1;i>=0;i--){
while(i>=j){
    ll sum=a[i];
    ans++;
    
    if(sum+a[j]<=x) j++;
 
    i--;
}
cout<<ans;
}
