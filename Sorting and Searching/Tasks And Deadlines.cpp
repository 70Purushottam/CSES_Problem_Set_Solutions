// C++ Solution

// Topics : sorting

#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main() {
	// your code goes here
int n;
cin>>n;
 
ll dsum=0;
ll arr[n];
for(int i=0;i<n;i++){
    ll a,d;
    cin>>a>>d;
    //if(i=0) 
    arr[i]=a;
    //else arr[i]=arr[i-1]+a;
    
    dsum += d;
}
 
sort(arr,arr+n);
ll asum=0;
for(int i=0;i<n;i++){
    if(i>0) arr[i]=arr[i-1]+arr[i];
    
    asum+=arr[i];
}
cout<<dsum-asum;
}