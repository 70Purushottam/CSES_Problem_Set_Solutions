// C++ Solution

// Tc=O(n * log(x))
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
 
vector<int> v(1e6,0);
 
for(int i=1;i<=1e6;i++){
    for(int j=i; j<=1e6; j+=i){
        v[j]++;
    }
}
int n;
cin>>n;
while(n--){
    int x;
    cin>>x;
    cout<<v[x]<<"\n";
}
}