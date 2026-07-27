// C++ Solution

// Topics : sorting 

#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int n;
  cin>>n;
  vector<tuple<int,int,int>> nums;
  multiset<pair<int,int>> mp;
  for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      nums.push_back(make_tuple(x,y,i+1));
  }
  vector<int> ans(n+1);
  int k=1;
  sort(nums.begin(),nums.end());
  mp.insert({get<1>(nums[0]),k});
  ans[get<2>(nums[0])]=(k++);
  
//   for(int i=0;i<n;i++){
//       cout<<get<0>(nums[i])<<" "<<get<1>(nums[i])<<" "<<get<2>(nums[i])<<"\n";
//   }
  
  for(int i=1;i<n;i++){
      pair<int,int> pairs=*(mp.begin());
      int p=(pairs.first);
      int q=(pairs.second);
      if(p<get<0>(nums[i])) {ans[get<2>(nums[i])]=q;//cout<<q<<" ";
       mp.insert({get<1>(nums[i]),q}); mp.erase(mp.find({p,q}));}
      else {ans[get<2>(nums[i])]=k;mp.insert({get<1>(nums[i]),k++});}
  }
  set<int> st;
  for(int i=1;i<=n;i++){
      st.insert(ans[i]);
  }
  cout<<st.size()<<"\n";
  for(int i=1;i<=n;i++){
      cout<<ans[i]<<" ";
  }
}