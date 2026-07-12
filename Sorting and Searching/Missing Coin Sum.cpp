// C++ Solution

// Topics: sorting

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
int n;
cin>>n;
vector<ll> v;
for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    v.push_back(x);
}
 
sort(v.begin(),v.end());
 
ll L=0;
 
for(int i=0;i<n;i++){
    if(L+1<v[i]) {cout<<L+1<<"\n";return 0;}
    L+=v[i];
}
cout<<L+1<<"\n";
}
