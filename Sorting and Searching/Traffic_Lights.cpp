// C++ Solution

// Topics : Multiset (ordered set which store multiple occurence of an element)

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
ll x,n;
cin>>x>>n;
set<ll> st;
multiset<ll> mt;
st.insert(0);
st.insert(x);
mt.insert(x);
 
for(int i=1;i<=n;i++){
    ll p;
    cin>>p;
    auto right=st.upper_bound(p);
    auto left=right;
    left--;
    ll l=*left,r=*right;
    
   if(mt.find(r-l)!=mt.end()) mt.erase(mt.find(r-l));// first find then erase only 1 occurence of (r-l)
    
    mt.insert(p-l);
    mt.insert(r-p);
    
    cout<<*(mt.rbegin())<<" ";
    
    st.insert(p);
}
}