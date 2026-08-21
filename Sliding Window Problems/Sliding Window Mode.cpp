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
   map<int, set<int>> mpf;
   
   for(int i = 0; i < n; i++){
       mp[arr[i]]++;
       if(mp[arr[i]] > 1){
           mpf[mp[arr[i]] - 1].erase(arr[i]);
       }
       mpf[mp[arr[i]]].insert(arr[i]);
       if(i >= k-1){
           auto it = mpf.rbegin();
          // it--;
           //cout<<it->first<<"\n";
           cout<<*((it->second).begin())<<" ";
           
          mpf[mp[arr[j]]].erase(arr[j]);
          if(mpf[mp[arr[j]]].size() == 0) mpf.erase(mp[arr[j]]);
           
           if(mp[arr[j]] > 1)  mpf[mp[arr[j]]-1].insert(arr[j]);
           
           mp[arr[j]]--;
           
           if(mp[arr[j]] == 0) mp.erase(arr[j]);
           
           j++;
       }
   }
}