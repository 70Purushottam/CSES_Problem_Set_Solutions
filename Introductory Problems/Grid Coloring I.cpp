// C++ Solution

// Topics: Simulation

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
 int n,m;
 cin>>n>>m;
 
 char grid[n][m];
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         cin>>grid[i][j];
     }
 }
 
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         //set<char> st;
         vector<char> v={'A','B','C','D'};
         if(i>0) v[grid[i-1][j]-'A']='1';
         if(j>0) v[grid[i][j-1]-'A']='1';
         v[grid[i][j]-'A']='1';
         for(int k=0;k<4;k++){
             if(v[k]!='1') {grid[i][j]=v[k];break;}
         }
         cout<<grid[i][j];
     }
     cout<<"\n";
 }
 
}
