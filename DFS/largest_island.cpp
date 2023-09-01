#include<bits/stdc++.h>

using namespace std;

int dfs(int i, int j, int m, int n, vector<vector<bool>> &grid, vector<vector<bool>> &visited){
    visited[i][j]=true;
    int ans = 1;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for(int d=0; d<4; d++){
        int x = i+dx[d];
        int y = j+dy[d];
        if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1 && !visited[x][y]){
            ans+=dfs(x, y, m, n, grid, visited);
        }
    }
    return ans;
}

int solve(int m, int n, vector<vector<bool>> &grid){
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int largest = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1 && !visited[i][j]){
                int size = dfs(i, j, m, n, grid, visited);
                if(size>largest) largest=size;
            }
        }
    }
    return largest;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, n;

    m = 5;
    n = 5;
    vector<vector<bool>> grid  = {
                            {1, 0, 0, 1, 0},
                            {1, 0, 1, 0, 0},
                            {0, 0, 1, 0, 1},
                            {1, 0, 1, 1, 1},
                            {1, 0, 1, 1, 0}
                            };
    cout << solve(m, n, grid);

    return 0;
}