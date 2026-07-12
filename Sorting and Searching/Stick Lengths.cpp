// C++ Solution

// Topics: sorting

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
int n;
cin>>n;
//double sum=0,
ll ans=0;
vector<ll> a;
for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    a.push_back(x);
}
sort(a.begin(),a.end());
//sum=sum/n;
for(int i=0;i<n;i++){
    ans+=abs(a[i]-a[n/2]);
}
ll ans1=0;
if(n%2==0){
   for(int i=0;i<n;i++){
    ans1+=abs(a[i]-a[n/2-1]);
    //ans=min(ans,ans1);
} 
}
cout<<ans;
}
