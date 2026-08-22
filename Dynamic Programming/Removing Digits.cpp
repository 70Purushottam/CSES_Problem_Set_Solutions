// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
vector<int> dp(n+1,INT_MAX);
dp[0]=0;
for(int i=1;i<=n;i++){
    string s=to_string(i);
    int ans=INT_MAX;
    for(char c:s){
        int digit=c-'0';
        if(digit!=0){
            dp[i]=min(dp[i],dp[i-digit]+1);
        }
    }
}
cout<<dp.back();
}