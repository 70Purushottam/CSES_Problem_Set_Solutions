// C++ Solution

// Topics : Bit Manipulation

# include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
int n;
cin>>n;
int num=1<<n;// 2^num
for(int i=0;i<num;i++){
    int k=(i^(i>>1));
    vector<int> v(n,0);
    int j=n-1;
    while(k>0){
        v[j--]=k%2;
        k/=2;
   // cout<<<<"\n";
    }
    for(int i=0;i<n;i++) cout<<v[i];
    cout<<"\n";
}
}