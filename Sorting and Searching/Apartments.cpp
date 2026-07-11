// C++ Solution

// Topics: sorting

#include <bits/stdc++.h>
using namespace std;
# define ll long long
 
int main() {
	// your code goes here
ll n,m,k;
cin>>n>>m>>k;
 
ll a[n];
ll b[m];
 
for(ll i=0;i<n;i++){
    cin>>a[i];
}
 
for(int i=0;i<m;i++){
    cin>>b[i];
}
 ll ans=0;
 
sort(a,a+n);
sort(b,b+m);
 
ll j=0;
for(ll i=0;i<n;i++){
    while(j<m){
        if(b[j]>=a[i]-k&& b[j]<=a[i]+k) {ans++;j++;break;}
        else if(b[j]>a[i]+k) break;
        j++;
    }
}
cout<<ans;
}
