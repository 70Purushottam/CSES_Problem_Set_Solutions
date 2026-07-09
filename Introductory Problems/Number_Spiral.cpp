// C++ Solution

// Topics : Observations


#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
 int t;
  cin>>t;
  while(t--){
     long long x,y;
     cin>>x>>y;
     long long ans=0;
   if(x>y && x%2==0) ans = x*x-y+1;
   else if(x>y && x%2!=0) ans = (x-1)*(x-1)+y;
   else if(x<=y && y%2!=0) ans = y*y-x+1;
   else if(x<=y && y%2==0) ans = (y-1)*(y-1)+x;

   cout<<ans<<"\n";

  }
}
