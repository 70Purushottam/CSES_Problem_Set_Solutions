// C++ Solution 

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
//int a[n];
unordered_map<int,int> mp;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
  //  a[i]=x;
    mp[x]++;
}
 
int ans=1;
 
for(int i=2;i<=1e6;i++){
    int cnt=0;
    for(int j=i;j<=1e6;j+=i){
    if(mp.find(j)!=mp.end()){
        cnt+=mp[j];
    }
    if(cnt>=2) {
        ans=max(ans,i);
        break;
    }
  }
}
cout<<ans<<"\n";
}