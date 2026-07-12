// C++ Solution

// Topics:hashmap 

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n,m;
cin>>n>>m;
int a[n];
unordered_map<int,int> mp;
mp[0]=0;
mp[n+1]=n+1;
for(int i=1;i<=n;i++) {cin>>a[i];mp[a[i]]=i;}
 
// counting rounds before any operations
 
int round=1;
for(int i=2;i<=n;i++){
    if(mp[i]<mp[i-1]) round++;
}
 
while(m--){
    int i,j;
    cin>>i>>j;
    if(i>j) swap(i,j);
    
    int x=a[i];
    int y=a[j];
    
    if(mp[x+1] > i && mp[x+1] < j) round++;
    if(mp[x-1] > i && mp[x-1] < j) round--;
    if(mp[y+1] > i && mp[y+1] < j) round--;
    if(mp[y-1] > i && mp[y-1] < j) round++;
    
    // case when consecutive elements
    if(x==(y+1)) round--;
    if(x==(y-1)) round++;
    
    cout<<round<<"\n";
    
    swap(a[i],a[j]);
    mp[x]=j;
    mp[y]=i;
}
}

