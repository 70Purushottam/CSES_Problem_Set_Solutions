// C++  Solution

// Topics: recursion, DP

# include <bits/stdc++.h>
using namespace std;
long long minans=INT_MAX;
void solve(vector<long long>& v,int n,long long g1,long long g2,int i){
    if(i==n) {
        minans=min(minans,abs(g1-g2));
        return ;
    }
    solve(v,n,g1+v[i],g2,i+1);
    solve(v,n,g1,g2+v[i],i+1);
}
int main() {
	// your code goes here
int n;
cin>>n;
vector<long long> v;
for(int i=0;i<n;i++){
   long long x;
    cin>>x;
    v.push_back(x);
   // cout<<x<<" ";
}
solve(v,n,0,0,0);
cout<<minans;
}