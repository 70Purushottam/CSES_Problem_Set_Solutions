// C++ Solution

#include <bits/stdc++.h>
# define ll long long
using namespace std;
 
int main() {
	
int n,k;
cin>>n>>k;
    ll x, a, b, c;
    cin>>x>>a>>b>>c;
    
    ll arr[n];
    arr[0] = x;
    
    for(int i= 1; i < n; i++){
         arr[i]= (a * arr[i-1] + b) % c;
    }
    
    ll p[n];
    
    for(int i = 0; i < n; i++){
        if(i % k ==0) p[i] = arr[i];
        else p[i] = p[i-1] | arr[i]; 
    }
    ll s[n];
    
    s[n-1] = arr[n-1];
    
    for(int i = n-2; i >= 0; i--){
        if( i %k == k-1) s[i] = arr[i];
        else s[i] = s[i+1] | arr[i];
    }
    
    ll ans = 0;
    
    for(int i = k-1; i < n; i++){
        ll curr = p[i] | s[i - k + 1];
        
        ans = ans ^ curr;
    }
    cout<<ans<<"\n";
}