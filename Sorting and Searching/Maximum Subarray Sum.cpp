// C++ Solution

// Topics: Sliding window , kadane's algorithm

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
int n;
cin>>n;
//map<int,int> mp;
vector<ll> a;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back(x);
   // mp[a[i]]=i;
}
 
ll ans=INT_MIN,sum=0;
int j=0;
for(int i=0;i<n;i++){
   ans=max(ans,a[i]);
   sum+=a[i];
   while(sum<0){
       sum-=a[j++];
   }
   if(sum!=0) ans=max(ans,sum);
}
cout<<ans<<"\n";
}
