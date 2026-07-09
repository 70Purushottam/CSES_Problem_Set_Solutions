// C++ Solution

// Topics : counting

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
long long n;
cin>>n;
long long MOD=1e9+7;
long long ans=1;
for(long long i=1;i<=n;i++){
    ans*=2;
    ans%=MOD;
}
cout<<ans;
}