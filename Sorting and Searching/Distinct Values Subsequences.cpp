// c++ Solution

// Topics : Hashmap

#include <bits/stdc++.h>
using namespace std;
# define ll long long
 
int main() {
	// your code goes here
int n;
cin>>n;
map<int,ll> mp;
for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    mp[x]++;
}
ll total=1;
ll mod=1e9+7;
for(auto it:mp){
    total *= (it.second+1);
    total %=mod;
}
 
cout<<total-1<<"\n";
}