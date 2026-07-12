
#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
int n;
cin>>n;
ll ans=0;
vector<pair<int,int>> a;
for(int i=0;i<n;i++){
int x,y;
    cin>>x>>y;
    a.push_back({y,x});
}
sort(a.begin(),a.end());
 
int prev=a[0].first;
ans++;
for(int i=1;i<n;i++){
    if(a[i].second>=prev){ans++;prev=a[i].first;}
}
cout<<ans;
}
