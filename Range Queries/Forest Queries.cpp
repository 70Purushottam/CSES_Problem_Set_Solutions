// C++ Solution

# include<bits/stdc++.h>
using namespace std;
# define ll long long
 
int main(){
  int n,q;
  cin>>n>>q;
  
  vector<string> v(n+1);
  for(int i=1;i<=n;i++){
      string s;
      cin>>s;
      v[i]=s;
      //cout<<s<<"\n";
  }
  vector<vector<int>> pre(n+1,vector<int> (n+1,0));
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
          if(v[i][j-1]=='*') pre[i][j]=1;
          pre[i][j]+=pre[i][j-1];
          //cout<<pre[i][j]<<" ";
      }
      //cout<<"\n";
  }
  
  while(q--){
      int r1,c1,r2,c2;
      cin>>r1>>c1>>r2>>c2;
      int ans=0;
      for(int i=r1;i<=r2;i++){
          ans+=pre[i][c2]-pre[i][c1-1];
      }
      cout<<ans<<"\n";
  }
}