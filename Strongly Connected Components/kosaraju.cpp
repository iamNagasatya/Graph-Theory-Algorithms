#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

const int N = 1e5+1;

vector<int> gr[N], grr[N], order;

int vis[N], col[N], deg[N];

void dfs1(int cur){
    vis[cur]=1;
    for(auto x: gr[cur]){
        if(!vis[x]){
            dfs1(x);
        }
    }
    order.push_back(cur);
}

void dfs2(int cur, int comp){
    vis[cur]=1;
    col[cur] = comp;
    for(int x: grr[cur]){
        if(!vis[x]){
            dfs2(x, comp);
        }
    }
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
        grr[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs1(i);
    }

    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof(vis));
    int comp=1;
    for(int x: order){
        if(!vis[x])
        dfs2(x, comp++);
    }
    
    for(int i=1; i<=n; i++){
        cout << i << " " << col[i] << endl;
    }

    for(int i=1; i<=n; i++){
        for(int j : gr[i]){
            if(col[i]!=col[j]) ++deg[col[j]];
        }
    }
    
    for(int i=1; i<comp; i++) cout << deg[i] << " ";
    return 0;
}