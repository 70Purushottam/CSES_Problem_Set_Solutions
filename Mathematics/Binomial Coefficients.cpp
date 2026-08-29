// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
 
struct Factorial {
    vector<ll> fact;
    vector<ll> invfact;
   
    int mod;
    ll modularBinaryExponentiation(int base, int exp){
        
        if(exp == 0) return 1;
        ll res = modularBinaryExponentiation(base,exp/2);
        if(exp % 2 ==1) return (((res * res) % mod) * base) % mod;
        else return (res * res) % mod;
    }
    
    Factorial(int n, int _mod){
        fact.resize(n+1);
        invfact.resize(n+1);
        mod = _mod;
        fact[0]=1;
        invfact[0]=1;
        
        for(int i=1;i<=n;i++){
        fact[i] = (fact[i-1] * i) % mod;
        invfact[i] =modularBinaryExponentiation(fact[i], mod-2);
    }
    }
    int factorialof(int x){
        return fact[x];
    }
    int invFactorialof(int x){
        return invfact[x];
    }
    
    int binomialCoff_Of(int a, int b){
        return (((fact[a] * invfact[a-b]) % mod) * invfact[b]) % mod;
    }
};
void solve(){
    int n, m;
    if (!(cin >> n >> m)) return;
    
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    Factorial fc = Factorial(1e6, 1e9+7);
    int m = 1e6+1;
    
    while(t--){
      int a,b;
      cin>>a>>b;
      cout<<fc.binomialCoff_Of(a,b)<<"\n";
    }
    return 0;
}