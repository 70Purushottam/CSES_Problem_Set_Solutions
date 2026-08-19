// C++ Solution

# include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long x,a,b,c;
    cin>>x>>a>>b>>c;
   long long ans=0,prev=x,dans=0,rem=x,cnt=0;
 
    for(int i=1;i<=n;i++){
        if(i==1){ dans ^=x;prev=x;}
        else {dans ^= (a*prev+b)%c;
        prev=(a*prev+b)%c;}
        cnt++;
        if(cnt==k){
            //cout<<dans<<" ";
            ans^=dans;
            dans^=rem;
            rem=(a*rem+b)%c;
            cnt--;
        }
    }
    cout<<ans;
 
}