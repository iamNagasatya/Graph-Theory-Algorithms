#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

int n, m, arr[100][100], dist[100][100];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> Q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j] = INT_MAX;
            if(arr[i][j]){
                Q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int k=0; k<4; k++){
            int xx = x+dx[k];
            int yy = y+dy[k];
            if(xx>=0 && xx<n && yy>=0 && yy<m && dist[xx][yy]==INT_MAX){
                Q.push({xx, yy});
                dist[xx][yy] = dist[x][y]+1;
            }
        }
    }
    cout << endl;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}