// C++ Solution

// Lazy Propagation Segment Build_Tree
 
 
# include<bits/stdc++.h>
using namespace std;
# define ll long long
vector<ll> sgt;
vector<ll> lazy;
void Build_Tree(vector<ll> &v, int i, int lo, int hi){
   if(lo==hi){
     sgt[i]=v[hi];
     return;
   }
   int mid=lo+(hi-lo)/2;
   Build_Tree(v,2*i+1,lo,mid);
   Build_Tree(v,2*i+2,mid+1,hi);
   sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}
 
void updateRange(int i,int lo, int hi, int& l, int& r, int& val){
    
    if(lazy[i]!=0){
      ll rangeSize=hi-lo+1;
        sgt[i]+=lazy[i]*rangeSize;
        if(lo!=hi){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>hi || r<lo) return;
    if(lo>=l && hi<=r){
        ll rangeSize=hi-lo+1;
        sgt[i]+=val*rangeSize;
        if(lo!=hi){
            lazy[2*i+1]+=val;
            lazy[2*i+2]+=val;
        }
        return;
    }
    int mid=lo+(hi-lo)/2;
    updateRange(2*i+1,lo,mid,l,r,val);
    updateRange(2*i+2,mid+1,hi,l,r,val);
    sgt[i]=sgt[2*i+1]+sgt[2*i+2];
}
 
ll getSum(int i, int lo, int hi, int& l,int& r){
    if(lazy[i]!=0){
      ll rangeSize=hi-lo+1;
        sgt[i]+=lazy[i]*rangeSize;
        if(lo!=hi){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
  if(l>hi || r<lo) return 0;
  if(lo>=l && hi<=r) return sgt[i];
  int mid=lo+(hi-lo)/2;
  return getSum(2*i+1,lo,mid,l,r) + getSum(2*i+2,mid+1,hi,l,r);
    
}
 
int main(){
  ll n,q;
  cin>>n>>q;
  vector<ll> v(n+1);
  for(int i=1;i<=n;i++){
    cin>>v[i];
  }
  sgt.resize(4*n);
  lazy.resize(4*n,0);
  Build_Tree(v,1,1,n);
  while(q--){
      int a,b,c,d;
      int k;
      cin>>a;
      if(a==1){
          cin>>b>>c>>d;
      }
      else{
          cin>>k;
      }
      if(a==1){
          updateRange(1,1,n,b,c,d); // Assuming 0 is the value to update with
      }
      else
      cout<<getSum(1,1,n,k,k)<<"\n";
  }
}