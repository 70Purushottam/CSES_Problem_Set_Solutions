// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
const int mod = 1e9+7; 
 
 
ll modularbinaryExponentiation(int base , int exp, int mod){
  if(exp == 0) return 1;
  
  ll res = modularbinaryExponentiation(base, exp/2, mod);
  
  if(exp % 2 == 1) return ((res * res) % mod * base) % mod;
  else return (res * res) % mod;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
int a,b,c;
cin>>a>>b>>c;
 
int exp = modularbinaryExponentiation(b, c, mod-1);
 
cout<< modularbinaryExponentiation(a, exp, mod)<<"\n";
 
}
}