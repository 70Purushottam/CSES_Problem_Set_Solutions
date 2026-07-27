// C++ Solution

// Topics : hashSet

#include <bits/stdc++.h>
using namespace std;
# define ll long long
 
int main() {
	// your code goes here
int n;
cin>>n;
set<int> st;
for(int i=1;i<=n;i++){
    st.insert(i);
}
int i=1;
while(st.size()>0){
    set<int> hlp;
    for(auto it:st){
        if(i%2==0 || st.size()==1) {
            cout<<it<<" ";
            hlp.insert(it);
        }
        i++;
    }
    for(auto it:hlp){
        st.erase(it);
    }
}
}
