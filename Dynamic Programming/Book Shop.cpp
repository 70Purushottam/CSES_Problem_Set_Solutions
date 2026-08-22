// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
int n,x;
cin>>n>>x;
 
vector<int> a(n);
vector<int> b(n);
vector<int> prev(x+1,0);
 
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    cin>>b[i];
}
for(int i=1;i<=n;i++){
    
    vector<int> curr(x+1);
    
    for(int j=0;j<=x;j++){
        int w=a[i-1];
        int val=b[i-1];
        
        int pick=(j>=w ? prev[j-w] + val : 0);
        int skip= prev[j];
        
        curr[j]= max(skip,pick);
    }
    prev=curr;
}
cout<<prev[x]<<"\n";
}