// C++ Solution

// Topics: Chess Game

# include <bits/stdc++.h>
using namespace std;
 
vector<pair<int,int>> offset={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
 
bool is_valid(int i,int j,int n){
    return i>=0 && i<n && j>=0 && j<n;
}
 
int main() {
	// your code goes here
int n;
cin>>n;

vector<vector<int>> grid(n,vector<int>(n,-1));
queue<pair<int,int>> q;
q.push({0,0});
grid[0][0]=0;

while(q.size()>0){
    pair<int,int> p=q.front();
    q.pop();
    int u=p.first;
    int v=p.second;
    for( auto i : offset){
        int j=u + i.first;
        int k=v + i.second;
        
        if(is_valid(j, k, n)&& grid[j][k] == -1){
            grid[j][k]= grid[u][v] +1;
            q.push({j,k});
        }
    }
}
 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<grid[i][j]<<" ";
    }
    cout<<"\n";
}
}
