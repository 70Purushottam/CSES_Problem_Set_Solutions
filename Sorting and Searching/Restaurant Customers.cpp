// C++ Solution

// Topics: sorting, binary search

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
int n;
cin>>n;
vector<int> v1,v2;
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    v1.push_back(x);
    v2.push_back(y);
}
sort(v1.begin(),v1.end());
vector<int> diff(n,1);
for(int i=0;i<n;i++){
    if(v2[i]>v1[n-1]) continue;
    auto it=lower_bound(v1.begin(), v1.end(),v2[i]);
    if(it==v1.end()) {
        continue;
    }
    int idx=it-v1.begin();
    //cout<<idx<<" ";
    diff[idx]--;
}
//cout<<"\n";
int sum=0,ans=0;
for(int i=0;i<n;i++){
    sum+=diff[i];
    ans=max(sum,ans);
}
cout<<ans<<"\n";
}
