// C++ Solution

// Topics: Hash Table

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
  long long n;
  cin>>n;
  vector<long long> v(n+1,0);
 for(int i=0;i<n-1;i++){
     int x;
     cin>>x;
     v[x]=1;
 }
 for(int i=1;i<=n;i++){
     if(v[i]==0) {cout<<i;
        break;}
 }
}
