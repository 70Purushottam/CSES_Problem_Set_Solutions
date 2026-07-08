// C++ Solution

// Topics: Count And Update

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
  int n;
  cin>>n;
  long long a[n];
  long long ans=0;
  for(int i=0;i<n;i++){
      cin>>a[i];
      if(i>0){
          if(a[i] < a[i-1]) {
            ans += a[i-1]-a[i];
            a[i] = a[i-1];
        }
      }
  }
  cout<<ans;
}
