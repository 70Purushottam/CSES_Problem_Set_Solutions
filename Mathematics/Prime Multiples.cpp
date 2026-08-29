// C++ Solution

#include <bits/stdc++.h>
using namespace std;
# define ll long long
 
int main() {
	// your code goes here
ll n;
cin>>n;
int k;
cin>>k;
 
vector<ll> v(k);
 
for(int i=0;i<k;i++){
    cin>>v[i];
}
ll ans=0;
vector<ll> countByNumbersOfDivisors(k+1);
 
for(int mask = 1; mask < (1<<k); mask++){
    int numberOfDivisors = 0;
    ll tmp = n;
    for(int i = 0; i < k; i++){
        if((1<<i) & mask){
            numberOfDivisors++;
            tmp /= v[i];
        }
    }
    countByNumbersOfDivisors[numberOfDivisors] += tmp;
}
for(int i = 1; i <= k; i++){
    if(i%2==0) ans -= countByNumbersOfDivisors[i];
    else ans += countByNumbersOfDivisors[i];
}
 
cout<<ans<<"\n";
}