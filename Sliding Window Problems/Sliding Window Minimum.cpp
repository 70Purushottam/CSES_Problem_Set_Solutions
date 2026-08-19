// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
 
int main() {
	// your code goes here
ll n,k;
cin>>n>>k;
 
ll x,a,b,c;
cin>>x>>a>>b>>c;
vector<ll> v(n+1);
v[1]=x;
for(int i=2;i<=n;i++){
   v[i]=(a*v[i-1] + b)%c;
}
 
ll ans=0;
 
deque<ll> dq;
 
for(int i=1;i<=n;i++){
  
  while(!dq.empty() &&  dq.back() > v[i] ) dq.pop_back();
  dq.push_back(v[i]);
  if(i<k) continue;
  if(i>k) {
      if(dq.front()==v[i-k]) dq.pop_front();
  }
  
  ans = (ans^dq.front());
  //cout<<dq.front()<< " "<<ans<<"\n";
}
cout<<ans;
}