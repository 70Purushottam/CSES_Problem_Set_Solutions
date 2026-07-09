// C++ Solution

// Topics: Maths

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int t;
cin>>t;
 
while(t--){
    long long a,b;
    cin>>a>>b;
    if((2*b-a)>=0 && ((2*b-a)%3==0) && (2*a-b)>=0 && ((2*a-b)%3==0)) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}
