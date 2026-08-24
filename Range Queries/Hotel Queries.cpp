// C++ Solution

# include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> sgt;
int n;
void Build_Tree(vector<int> &v, int i, int lo, int hi){
   if(lo==hi){// base case leaf node
     sgt[i]= {v[hi], hi};
     return;
   }
   int mid=lo+(hi-lo)/2;
   Build_Tree(v,2*i+1,lo,mid);
   Build_Tree(v,2*i+2,mid+1,hi);
   sgt[i].first=max(sgt[2*i+1].first, sgt[2*i+2].first);
   sgt[i].second=(sgt[2*i+1].first>=sgt[2*i+2].first)? sgt[2*i+1].second: sgt[2*i+2].second;
}
 
void updateVal(int i,int lo, int hi, int& index , int val){
    if(lo==hi){// base case leaf node
        sgt[i]= {val, index};
        return;
    }
    int mid=lo+(hi-lo)/2;
    if(index<=mid) updateVal(2*i+1,lo,mid,index,val);
    else updateVal(2*i+2, mid+1,hi,index,val);
    sgt[i]= {max(sgt[2*i+1].first, sgt[2*i+2].first), sgt[i].second}; // (BackTracking) update the parent node after updating the child node
}
 
int check(int i, int lo, int hi, int l, int r,int target){
  if(l>hi || r<lo || sgt[i].first < target) return 0;// No overlapping region
 
  if(lo==hi){//>=l && hi<=r ) {
    updateVal(1,1,n,sgt[i].second,sgt[i].first-target);
    return sgt[i].second;}
 
  int mid=lo+(hi-lo)/2;
  int x=check(2*i+1,lo,mid,l,r,target);
  if(x>0) return x;
  else return check(2*i+2,mid+1,hi,l,r,target);
    return 0;
}
 
int main(){
  int m;
  cin>>n>>m;
  vector<int> v(n+1);
  for(int i=1;i<=n;i++){
    cin>>v[i];
  }
  vector<int> r(m+1);
  for(int i=1;i<=m;i++){
    cin>>r[i];
  }
  sgt.resize(4*n);
  Build_Tree(v,1,1,n);
  int i=1;
  while(m--){
      
      cout<<check(1,1,n,1,n,r[i++])<<" ";
  }
}