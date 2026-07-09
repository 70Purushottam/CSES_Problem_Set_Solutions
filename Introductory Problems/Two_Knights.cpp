// C++ Solution

// Topics : Matrix 


#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
long long n;
cin>>n;
for(long long i=1;i<=n;i++){
    long long Total_Ways=((i*i)*(i*i-1))/2;
    long long Num_Attacking_place=4*(i-1)*(i-2);
    cout<<Total_Ways-Num_Attacking_place<<"\n";
}
}