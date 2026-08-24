// C++ Solution

# include<bits/stdc++.h>
using namespace std;
vector<int> sgt;
void Build_Tree(vector<int> &v, int i, int lo, int hi){
   if(lo==hi){
     sgt[i]=v[lo];
     return;
   }
   int mid=lo+(hi-lo)/2;
   Build_Tree(v,2*i+1,lo,mid);
   Build_Tree(v,2*i+2,mid+1,hi);
   sgt[i]=min(sgt[2*i+1],sgt[2*i+2]);
}
 
int getMin(int i, int lo, int hi, int l, int r){
  if(lo>r || hi<l) return INT_MAX;
  if(lo>=l && hi<=r) return sgt[i];
  int mid=lo+(hi-lo)/2;
  return min(getMin(2*i+1,lo,mid,l,r),getMin(2*i+2,mid+1,hi,l,r));
    
}
 
int main(){
  int n,q;
  cin>>n>>q;
  vector<int> v(n+1);
  for(int i=1;i<=n;i++){
    cin>>v[i];
  }
  sgt.resize(4*n);
  Build_Tree(v,1,1,n);
  
  while(q--){
      int a,b;
      cin>>a>>b;
      cout<<getMin(1,1,n,a,b)<<"\n";
  }
}