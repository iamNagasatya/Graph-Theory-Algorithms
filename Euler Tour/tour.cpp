#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

const int N = 1e5+1;

int tmein[N], tmeout[N], tme, flat[N], pre[N];

vector<int> gr[N];

void dfs(int cur, int par){
    tmein[cur]=++tme;
    for(int x: gr[cur]){
        if(x!=par){
            dfs(x, cur);
        }
    }
    tmeout[cur]=tme;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    dfs(1, 0);

    for(int i=1; i<=n; i++){
        flat[tmein[i]] = i;
    }
    pre[0]=flat[0];
    for(int i=1; i<=n; i++){
        pre[i] = flat[i]+pre[i-1];
    }


    cout << pre[tmeout[k]]-pre[tmein[k]-1] << endl;

    return 0;
}