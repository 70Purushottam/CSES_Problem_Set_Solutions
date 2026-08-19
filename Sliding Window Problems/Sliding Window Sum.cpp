# include <bits/stdc++.h>
using namespace std;
 
int main() {
int n,k;
cin>>n>>k;
int x,a,b,c;
cin>>x>>a>>b>>c;
long long sum=x,prev=x,prev1=0;
for(int i=1;i<k;i++){
   sum +=(a*prev+b)%c;
   prev=(a*prev+b)%c;
}
prev1=prev;
prev=x;
long long ans =0;
ans=sum;
for(int i=k;i<n;i++){
     sum -= prev;
    prev =(a*prev+b)%c;
    sum +=(a*prev1+b)%c;
   prev1=(a*prev1+b)%c;
    ans ^= sum;
}
cout<<ans;
 
}