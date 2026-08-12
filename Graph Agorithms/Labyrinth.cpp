// C++ Solutions

// Topics : BFS


#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, m;
    if (!(cin >> n >> m)) return;
    
    vector<vector<char>> edges(n, vector<char>(m));
    int sr = -1, sc = -1, er = -1, ec = -1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> edges[i][j];
            if(edges[i][j] == 'A') { sr = i; sc = j; }
            if(edges[i][j] == 'B') { er = i; ec = j; }
        }
    }
 
    // parentDir stores the direction character used to reach this cell
    vector<vector<char>> parentDir(n, vector<char>(m, 0));
    // visited array to prevent re-processing cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    // parentCell stores the {row, col} we came from
    vector<vector<pair<int, int>>> parentCell(n, vector<pair<int, int>>(m, {-1, -1}));
    
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
 
    // Up, Right, Left, Down matching your exact dr/dc logic order
    int dr[] = {-1, 0, 0, 1};
    int dc[] = {0, 1, -1, 0};
    char moveDir[] = {'U', 'R', 'L', 'D'};
 
    bool found = false;
 
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
 
        if (r == er && c == ec) {
            found = true;
            break;
        }
 
        for (int i = 0; i < 4; i++) {
            int nrow = r + dr[i];
            int ncol = c + dc[i];
 
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && (edges[nrow][ncol] == '.' || edges[nrow][ncol] == 'B')) {
                visited[nrow][ncol] = true;
                parentCell[nrow][ncol] = {r, c};
                parentDir[nrow][ncol] = moveDir[i];
                q.push({nrow, ncol});
            }
        }
    }
 
    if (found) {
        cout << "YES" << "\n";
        string path = "";
        int curr_r = er, curr_c = ec;
        
        // Backtrack from 'B' to 'A'
        while (curr_r != sr || curr_c != sc) {
            path += parentDir[curr_r][curr_c];
            auto [p_r, p_c] = parentCell[curr_r][curr_c];
            curr_r = p_r;
            curr_c = p_c;
        }
        
        // Since we backtracked, the path is reversed
        reverse(path.begin(), path.end());
        
        cout << path.length() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO" << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}