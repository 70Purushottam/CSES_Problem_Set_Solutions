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
 
 
#define ll long long
#define len(x) int(x.size())
 
void solve() {
    int n, k;
    cin >> n >> k;
 
 
    ordered_multiset<int> st;
    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;
    int j = 0;
    ll cnt = 0;;
    
    for(int i = 0; i< n; i++){
        
        auto it = st.order_of_key(arr[i]+1);
        int idx = 0;
        ll diff = st.size()-it;
        cnt += diff;
        st.insert(arr[i]);
        if(i>=k-1){
            cout<<cnt<<" ";
        auto it = st.order_of_key(arr[j]);
        ll idx = it;
        st.erase(st.find_by_order(st.order_of_key(arr[j])));
        cnt -= idx;
        j++;
        }
        
    }
}
 
int main() {
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}