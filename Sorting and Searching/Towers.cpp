// C++ Solutions

// Topics : Binary search

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
int cnt=0;
//vector<int> v;
vector<int> hlp(n,INT_MAX);
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(i==0) hlp[cnt++]=x;
    else{
        auto it=upper_bound(hlp.begin(),hlp.end(),x);
        if(*it==INT_MAX) hlp[cnt++]=x;
        else{
            int idx=it-hlp.begin();
            hlp[idx]=x;
        }
    }
}
cout<<cnt<<"\n";
}
