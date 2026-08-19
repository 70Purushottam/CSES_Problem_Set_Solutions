// C++ Solution

#include <bits/stdc++.h>
# define ll long long
using namespace std;
 
int main() {
	// your code goes here
    int n,k;
    cin>>n>>k;
 
    int arr[n];
    
    for(int i= 0; i < n; i++){
         cin>>arr[i];
    }
    
   int j = 0;
   map<int,int> mp;
   for(int i = 0; i < n; i++){
       mp[arr[i]]++;
       if(i >= k-1){
          
           cout<<mp.size()<<" ";
           mp[arr[j]]--;
           if(mp[arr[j]] == 0) mp.erase(arr[j]);
           j++;
       }
   }
}