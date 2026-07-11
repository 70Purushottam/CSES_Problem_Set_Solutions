// C++ Solution

// Topics: Backtracking, Path Optimisation

#include <bits/stdc++.h>
using namespace std;
 
const int n=7;
vector<vector<int>> vis(n, vector<int>(n,0));
int ans=0;
 
bool is_possible(int j, int k){
    return j>=0 && j<n && k>=0 && k<n;
}
 
 
void func(string& s, int i, int j, int k){
    if(i >= n*n - 1 || (j==n-1&&k==0)){
        if((i == n*n - 1) && (j==n-1&&k==0)) ans++;
        return;
    }
    
    // Boxed in optimisation
    
    //above and below visited(or out of bound); left and right free
    if((!is_possible(j-1,k) || vis[j-1][k]) && (!is_possible(j+1,k) || vis[j+1][k])){
     if((is_possible(j,k-1) && !vis[j][k-1]) && (is_possible(j,k+1) && !vis[j][k+1])) {return;}}
     
      //left and right visited(or out of bound); up and down free
     if((!is_possible(j,k-1) || vis[j][k-1]) && (!is_possible(j,k+1) || vis[j][k+1])){
        if((is_possible(j-1,k) && !vis[j-1][k]) && (is_possible(j+1,k) && !vis[j+1][k])) {return;}}
    
    vis[j][k]=1;
    
    
    if((s[i]=='U' || s[i]=='?') && is_possible(j-1,k) && !vis[j-1][k]) func(s,i+1,j-1,k);
    
    if((s[i]=='D' || s[i]=='?') && is_possible(j+1,k) && !vis[j+1][k]) func(s,i+1,j+1,k);
    
    if((s[i]=='L' || s[i]=='?') && is_possible(j,k-1) && !vis[j][k-1]) func(s,i+1,j,k-1);
    
    if((s[i]=='R' || s[i]=='?') && is_possible(j,k+1) && !vis[j][k+1]) func(s,i+1,j,k+1);
    
    vis[j][k]=0;
   
}
 
int main() {
	// your code goes here
string s;
cin>>s;
func(s,0,0,0);
cout<<ans;
}