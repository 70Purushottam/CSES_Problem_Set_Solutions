// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int mod=1e9+7;
int main() {
	// your code goes here
int n,q;
cin>>n>>q;
 
vector<ll> v(n+1,0);
 
for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    v[i]=v[i-1]+x;
}
 
while(q--){
    int a,b;
    cin>>a>>b;
    cout<<v[b]-v[a-1]<<"\n";
}
}