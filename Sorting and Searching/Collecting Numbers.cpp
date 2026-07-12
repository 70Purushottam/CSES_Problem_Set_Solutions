// C++ Solution

// Topics:hashmap 

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
map<int,int> mp;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    mp[x]=i+1;
}
 
int ans=0,j=1,cnt=0,prev=0;
while(1){
     ans++;
    prev= mp[j++];
    cnt++;
     while(j<=n){
     if(mp[j]>prev){
         prev=mp[j];
     }
     else{
         break;
     }
     prev=mp[j];
     cnt++;
     j++;
  }
  if(cnt>=n) break;
 }
 cout<<ans<<"\n";
}
