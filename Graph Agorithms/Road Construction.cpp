// C++ Solution

#include <bits/stdc++.h>
using namespace std;
 
class DisjointSet{
public: // Made public so main() can access the size array directly
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) size[i] = 1;
        for(int i=0;i<=n;i++) parent[i] = i;
    }
 
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
 
    void UnionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
 
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
 
    void UnionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    if (!(cin >> n >> m)) return 0;
 
    // 1. Initialize the Disjoint Set with n elements
    DisjointSet ds(n);
 
 
    int components = n;
    int max_size = 1;
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
 
        // 3. Find ultimate parents before joining
        int p_u = ds.findUPar(u);
        int p_v = ds.findUPar(v);
 
        // 4. If they belong to different components, merge them
        if (p_u != p_v) {
            ds.UnionBySize(u, v);
            components--; // Merging two components decreases total count by 1
            
            // Get the root of the newly merged single component
            int new_root = ds.findUPar(u); 
            max_size = max(max_size, ds.size[new_root]);
        }
 
        // 5. Output results after each day
        cout << components << " " << max_size << "\n";
    }
    
    return 0;
}
