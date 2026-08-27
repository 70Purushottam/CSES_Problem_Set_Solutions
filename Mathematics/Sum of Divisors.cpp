// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
const int mod = 1e9+7;
 
ll modularbinaryExponentiation(int base , int exp){
  if(exp == 0) return 1;
  
  ll res = modularbinaryExponentiation(base, exp/2);
   //res %= mod;
  if(exp % 2 == 1) return ((res * res) % mod * base) % mod;
  else return (res * res) % mod;
}
 
int main() {
	// your code goes here
ll n;
cin>>n;
ll ans=0;
for(ll i= 1,j; i <= n; i = j){
   ll q = n/i;
   j = n/q + 1;
  
  ll sumUpto_J_minus_one = ((((j % mod) * ((j-1) % mod)) % mod) * modularbinaryExponentiation(2, mod-2)) % mod;
  
  ll sumUpto_I_minus_one = ((((i % mod) * ((i-1) % mod))% mod) * modularbinaryExponentiation(2, mod-2)) % mod;
  
  ll rangewithQuotientQ = (sumUpto_J_minus_one - sumUpto_I_minus_one +mod) % mod;
  
   ans = (ans + (q%mod) * rangewithQuotientQ) % mod;
  // ans %= mod;
}
cout<<ans<<"\n";
}