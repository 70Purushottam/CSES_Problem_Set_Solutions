#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
int n, m;
vector<string> grid;
vector<vector<int>> monster_dist;
vector<vector<int>> player_dist;
vector<vector<pair<int, int>>> parent;
 
// Directions: Down, Up, Left, Right
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir_chars[] = {'D', 'U', 'L', 'R'};
 
bool is_valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#');
}
 
bool is_boundary(int x, int y) {
    return (x == 0 || x == n - 1 || y == 0 || y == m - 1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    if (!(cin >> n >> m)) return 0;
 
    grid.resize(n);
    monster_dist.assign(n, vector<int>(m, INF));
    player_dist.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));
 
    queue<pair<int, int>> mq;
    pair<int, int> start_pos;
 
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monster_dist[i][j] = 0;
                mq.push({i, j});
            } else if (grid[i][j] == 'A') {
                start_pos = {i, j};
            }
        }
    }
 
    // 1. Multi-source BFS for Monsters
    while (!mq.empty()) {
        auto [x, y] = mq.front();
        mq.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_valid(nx, ny) && monster_dist[nx][ny] == INF) {
                monster_dist[nx][ny] = monster_dist[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }
 
    // 2. BFS for Player 'A'
    queue<pair<int, int>> pq;
    pq.push(start_pos);
    player_dist[start_pos.first][start_pos.second] = 0;
 
    pair<int, int> escape_point = {-1, -1};
 
    while (!pq.empty()) {
        auto [x, y] = pq.front();
        pq.pop();
 
        // If we reached a boundary square safely, stop
        if (is_boundary(x, y)) {
            escape_point = {x, y};
            break;
        }
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int next_dist = player_dist[x][y] + 1;
 
            // Player must reach the square STRICTLY before any monster
            if (is_valid(nx, ny) && player_dist[nx][ny] == INF && next_dist < monster_dist[nx][ny]) {
                player_dist[nx][ny] = next_dist;
                parent[nx][ny] = {x, y};
                pq.push({nx, ny});
            }
        }
    }
 
    // 3. Output Results and Reconstruction
    if (escape_point.first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        string path = "";
        pair<int, int> curr = escape_point;
 
        while (curr != start_pos) {
            pair<int, int> prev = parent[curr.first][curr.second];
            
            // Determine direction taken
            for (int i = 0; i < 4; i++) {
                if (prev.first + dx[i] == curr.first && prev.second + dy[i] == curr.second) {
                    path += dir_chars[i];
                    break;
                }
            }
            curr = prev;
        }
 
        reverse(path.begin(), path.end());
        cout << path.length() << "\n" << path << "\n";
    }
 
    return 0;
}
