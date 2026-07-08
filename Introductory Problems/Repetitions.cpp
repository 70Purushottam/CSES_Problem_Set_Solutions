// C++ Solutions

// Topics : Counting

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
  string s;
  cin>>s;
  int n=s.size();
  int cnt=1,ans=1;
  for(int i=0;i<n-1;i++){
      if(s[i]==s[i+1]) cnt++;
      else cnt=1;
      ans=max(ans,cnt);
  }
  cout<<ans;
}
