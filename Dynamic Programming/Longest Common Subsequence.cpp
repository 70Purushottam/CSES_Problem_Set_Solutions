// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
 
    int n, m;
    cin >> n >> m;
 
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
 
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                v[i][j] = 1 + v[i - 1][j - 1];
            } else {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
 
    cout << v[n][m] << "\n";
 
    
    vector<ll> ans;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        } else if (v[i - 1][j] >= v[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
 
    reverse(ans.begin(), ans.end());
 
    for (int k = 0; k < ans.size(); k++) {
        cout << ans[k] << (k == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
 
    return 0;
}
