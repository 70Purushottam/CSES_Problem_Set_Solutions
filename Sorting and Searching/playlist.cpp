// C++ Solution
// Topics : hashSet

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
vector<int> v;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
}
 
int ans=1,j=0;
set<int> st;
for(int i=0;i<n;i++){
    if(st.find(v[i])!=st.end()){
        while(j<i){
            st.erase(v[j++]);
            if(st.find(v[i])==st.end()) break;
        }
        st.insert(v[i]);
    } 
    else st.insert(v[i]);
    int k=st.size();
    ans=max(ans,k);
}
cout<<ans<<"\n";
}
