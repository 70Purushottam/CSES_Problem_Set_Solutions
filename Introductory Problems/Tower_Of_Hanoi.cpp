// C++ Solution

// Topics: Recursion

# include <bits/stdc++.h>
using namespace std;
 
void helper(int n,int s,int h,int d){
    if(n==0){
       return; 
    }
    helper(n-1,s,d,h);
    cout<<s<<" "<<d<<"\n";
    helper(n-1,h,s,d);
}
 
int main() {
	// your code goes here
	int n;
	cin>>n;
	long long ans=pow(2,n);
	cout<<ans-1<<"\n";
	helper(n,1,2,3);
	
}
