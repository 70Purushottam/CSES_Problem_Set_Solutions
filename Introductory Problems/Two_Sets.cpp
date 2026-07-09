// C++ Solution

// Topics : 



#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
long long n;
cin>>n;
long long sum=n*(n+1)/2;
if(sum%2!=0) cout<<"NO";
else{
  cout<<"YES"<<"\n";
  cout<<n-n/2<<"\n";
  if(n%2!=0) {for(int i=1;i<=n-n/2;i+=2){
      cout<<i<<" "<<n-i<<" ";
  }
  cout<<"\n";
  cout<<n/2<<"\n";
  cout<<n<<" ";
  for(int i=2;i<=n-n/2-2;i+=2){
      cout<<i<<" "<<n-i<<" ";
  }
  cout<<"\n";
    }
    else{
        for(int i=1;i<=n/2;i+=2){
            cout<<i<<" "<<n-i+1<<" ";
        }
        cout<<"\n";
        cout<<n/2<<"\n";
        for(int i=2;i<=n/2;i+=2){
            cout<<i<<" "<<n-i+1<<" ";
        }
        cout<<"\n";
    }
}
}