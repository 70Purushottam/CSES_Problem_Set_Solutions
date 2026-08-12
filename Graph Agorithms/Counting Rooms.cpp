// C++ Solution

// Topics : Depth-First search

#include <bits/stdc++.h>
using namespace std;
int n,m;
void dfs(vector<string>& v,int i,int j,vector<vector<int>>& vis){
    vis[i][j]=1;
    if(i-1>=0 && vis[i-1][j]==0 && v[i-1][j]=='.') dfs(v,i-1,j,vis);
    if(i+1<n && vis[i+1][j]==0 && v[i+1][j]=='.') dfs(v,i+1,j,vis);
    if(j-1>=0 && vis[i][j-1]==0 && v[i][j-1]=='.') dfs(v,i,j-1,vis);
    if(j+1<m && vis[i][j+1]==0 && v[i][j+1]=='.') dfs(v,i,j+1,vis);
}
int main(){   
    
    //int n,m;
    cin>>n>>m;
    
    vector<string> v;
    
    for(int i=0;i<n;i++){
    string s;
    cin>>s;
    v.push_back(s);
   }
   vector<vector<int>> vis(n,vector<int> (m,0));
   int cnt=0;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(v[i][j]=='.' && vis[i][j]==0){
               dfs(v,i,j,vis);
               cnt++;
           }
       }
   }
  cout<<cnt<<"\n"; 
   
}