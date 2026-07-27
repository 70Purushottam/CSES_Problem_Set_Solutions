// C++ Solution

// Topics : Hashmap, sorting using custom comparator

# include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
 
vector<pair<int,int>> vec;
map<pair<int,int>,int> mp;
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    vec.push_back({x,y});
    mp[{x,y}]=i;
}
 
sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
    if(a.first==b.first) return a.second>b.second;
        return a.first < b.first;
    });
 
int maxi=0,mini=INT_MAX;
int ans2[n];
int ans1[n];
 
for(int i=n-1;i>=0;i--){
    int idx = mp[vec[i]];
   if(vec[i].second>=mini) ans1[idx]=1;
   else{ ans1[idx]=0;mini=vec[i].second;}
}
for(int i=0;i<n;i++){
   int idx = mp[vec[i]];
   if(vec[i].second<=maxi) ans2[idx]=1;
   else{ ans2[idx]=0;maxi=vec[i].second;}
}
for(int i=0;i<n;i++){
    cout<<ans1[i]<<" ";
}
cout<<"\n";
for(int i=0;i<n;i++){
    cout<<ans2[i]<<" ";
}
cout<<"\n";
}