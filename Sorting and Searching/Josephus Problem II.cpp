// C++ Solution

// Topics : PBDS (policy based data structure) (ordered set)

#include <bits/stdc++.h>
# include<ext/pb_ds/assoc_container.hpp>
# include<ext/pb_ds/tree_policy.hpp>
using namespace std;
# define ll long long
 
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type, less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
# define len(x) int((x).size())
 
int main() {
	// your code goes here
int n,k;
cin>>n>>k;
ordered_set nums;
for(int i=1;i<=n;i++){
    nums.insert(i);
}
 
int pos=0;
 
while(!nums.empty()){
    
    pos=(pos+k)%len(nums);
    
    auto it = nums.find_by_order(pos);
    cout<<*it<<" ";
    nums.erase(it);
}
}