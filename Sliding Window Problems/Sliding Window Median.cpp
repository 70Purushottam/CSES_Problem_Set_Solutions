// C++ Solution

#include <bits/stdc++.h>
// Required PBDS headers
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds;
 
// Defining ordered_multiset using the less_equal trick
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main() {
	// your code goes here
	
	int n,k;
	cin>>n>>k;
   int a[n];
   ordered_multiset<int> st;
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   int j = 0;
   for(int i=0;i<n;i++){
       st.insert(a[i]);
       
       if(i>=k-1){
           cout<<*(st.find_by_order((k-1)/2))<<" ";
           st.erase(st.find_by_order(st.order_of_key(a[j])));
           j++;
       }
   }
   }