// C++ Solution

// Topics : sorting and constructive algorithm

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
int n;
cin>>n;
 
ll tsum = 0;
vector<ll> v;
for(int i=0;i<n;i++){
   ll x;
   cin>>x;
   v.push_back(x);
  // revsum += x;
  tsum += x;
}
 
sort(v.begin(),v.end());
ll stsum=0;

for(int i=n-2;i>0;i--){
    stsum += v[i];
}
if(v[n-1] > stsum) stsum += v[n-1] - stsum;
stsum += v[n-1];
cout<<max(tsum,stsum);
}