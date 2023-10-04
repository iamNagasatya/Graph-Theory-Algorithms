#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

const int N = 1e5+1;

vector<int> gr[N];
vector<int> order;
int vis[N], Par[N];

void dfs(int cur, int par){
    vis[cur]=1;
    Par[cur]=par;
    for(int x: gr[cur]){
        if(!vis[x]){
            dfs(x, cur);
        }
        else if(x!=par && vis[x]==1){
            int u=cur, v=x;
            while(u!=v){
                cout << u << " ";
                u = Par[u];
            }
            cout << u << endl;
            exit(0);
        }
    }
    vis[cur]=2;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }

    return 0;
}