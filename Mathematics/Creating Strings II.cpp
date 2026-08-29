// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
const int mod = 1e9+7;
ll power(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
 
// Function to calculate modular inverse of n modulo prime 'mod'
ll modInverse(ll n) {
    return power(n, mod - 2);
}
 
// Fixed nCr function using Modular Multiplicative Inverse
ll nCr(int n, int r){
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    r = min(r, n - r);
    ll res = 1;
    
    for(ll i = 1; i <= r; i++){
        // Multiply by the numerator term under modulo
        res = (res * (n - r + i)) % mod;
        // Multiply by the modular inverse of the denominator term i
        res = (res * modInverse(i)) % mod;
    }
    return res;
}
 
int main() {
	// your code goes here
string s;
cin>>s;
int n = s.size();
map<char,int> mp;
for(int i=0;i<n;i++){
    mp[s[i]]++;
}
ll ans = 1;
 
for(auto it: mp){
   ans = ans*(nCr(n,it.second));
   ans %= mod;
   n -= it.second; 
}
cout<<ans<<"\n";
}