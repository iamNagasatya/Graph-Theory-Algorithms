
#include <bits/stdc++.h>

using namespace std;

int n, m, arr[100][100], visited[100][100], color[150];

void flood_fill(int i, int j, int col){
    visited[i][j]=col;
    color[col]++;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    for(int k=0; k<4; k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(x>=0 && x<n && y>=0 && y<m && arr[x][y]==1 && !visited[x][y]){
            flood_fill(x, y, col);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1 && !visited[i][j]){
                cnt++;
                flood_fill(i, j, cnt);
            }
        }
    }
    
    cout << cnt << endl;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i=1; i<=cnt; i++){
        cout << color[i] << " ";
    }

    return 0;
}