// C++ solution

// Topics : hashSet

# include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
vector<int> v;
set<int> st;
//vector<int> hlp(n,INT_MAX);
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
}
   
   int j=0;
   long long ans=0;
    
    for(int i=0;i<n;i++){
    if(st.find(v[i])!=st.end()) {
        while(j<i){
            st.erase(v[j++]);
            if(st.find(v[i])==st.end()) break;
        }
    }
        st.insert(v[i]);
        ans+=st.size();
}
cout<<ans<<"\n";
}