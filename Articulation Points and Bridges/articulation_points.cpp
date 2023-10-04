#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

const int N = 1e5+1;

vector<int> gr[N];
int vis[N], dis[N], low[N], tme=1;

void dfs(int cur, int par){
    vis[cur]=1;
    dis[cur]=low[cur]=tme++;
    int child=0;
    for(int x: gr[cur]){
        if(!vis[x]){
            dfs(x, cur);
            low[cur] = min(low[cur], low[x]);
            child++;
            if(par!=0 && low[x]>=dis[cur]){
                cout << cur << endl;
            }
        }
        else if(x!=par){
            low[cur]=dis[x];
        }
    }

    if(par==0 && child>1){
        cout << cur << endl;
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
        gr[y].push_back(x);
    }

    dfs(1, 0);

    return 0;
}