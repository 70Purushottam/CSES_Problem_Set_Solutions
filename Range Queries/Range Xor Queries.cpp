// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int n,q;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	   if(i!=0) a[i] =((a[i])^(a[i-1]));
	}
vector<pair<int,int>> v;
	while(q--){
	    int l,r;
	    cin>>l>>r;
	    v.push_back({l,r});
	}
	int b=v.size();
	for(int i=0;i<b;i++){
	    int l,r;
	    l=v[i].first;
	    r=v[i].second;
	    if(l>1) cout<<(((a[r-1])^(a[l-2])))<<"\n";
	    else cout<<(a[r-1])<<"\n";
}