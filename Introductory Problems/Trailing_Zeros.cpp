// C++ Solution

// Topics: Counting

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
long long n;
cin>>n;
long long ans=0,k=5;
while(n>=k){
    ans+=n/k;
    k*=5;
}
cout<<ans<<"\n";
}
