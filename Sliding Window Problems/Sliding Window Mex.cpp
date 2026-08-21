// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
 int n,k;
 cin>>n>>k;
 
 int arr[n];
 for(int i =0;i<n;i++){
     cin>>arr[i];
 }
 
 set<int> unseen_ele;
 map<int,int> seen_ele;
 
for(int i = 0; i <= k; i++){
        unseen_ele.insert(i);
}
 
 int j = 0;
 
 for(int i = 0; i < n; i++){
     seen_ele[arr[i]]++;
     if(seen_ele[arr[i]] == 1) unseen_ele.erase(arr[i]);
     
     if(i-j+1 < k) continue;
     else{
     cout<<*unseen_ele.begin()<<" ";
 
     if(seen_ele[arr[j]]==1) {
         seen_ele.erase(arr[j]);
         unseen_ele.insert(arr[j]);
     }
     else seen_ele[arr[j]]--;
     j++;
 }
 }
 
}