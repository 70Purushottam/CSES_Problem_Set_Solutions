// C++ Solution

#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main() {
	// your code goes here
int n;
cin>>n;
 
vector<string> v;
for(int i=0;i<n;i++){
    string s;
    cin>>s;
    v.push_back(s);
}
 
vector<vector<int>> dp(n,vector<int>(n,0));
if(v[0][0]!='*') dp[0][0]=1;
 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(v[i][j]!='*') {
                int up=0;
                if(i-1>=0) up=dp[i-1][j];
                int left=0;
               if(j-1>=0) left=dp[i][j-1];
                dp[i][j]+=up+left;
                dp[i][j]%=mod;
            }
    }
}
cout<<dp[n-1][n-1];
}