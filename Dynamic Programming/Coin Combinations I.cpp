// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
 
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
 
    // 1. Sort coins to enable early breaking in the inner loop
    sort(coins.begin(), coins.end());
 
    int mod = 1e9 + 7;
    vector<int> tp(x + 1, 0);
    tp[0] = 1;
 
    // 2. DP loop
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] > i) {
                break; // Because coins are sorted, all subsequent coins will also be > i
            }
            tp[i] = (tp[i] + tp[i - coins[j]]) % mod;
        }
    }
 
    cout << tp[x];
    return 0;
}