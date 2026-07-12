#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
int n,x;
cin>>n>>x;
map<int,int> mp;
vector<int> a;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back(x);
    mp[a[i]]=i;
}
 
for(int i=0;i<n;i++){
    if(a[i]>x) continue;
   if(mp.find(x-a[i])!=mp.end()&&mp[x-a[i]]!=i) {
       cout<<i+1<<" "<<mp[x-a[i]]+1<<"\n";
       return 0;}
}
cout<<"IMPOSSIBLE"<<"\n";
}
