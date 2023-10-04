#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

const int N = 1e5+1;

vector<int> gr[N];
int Par[N], dep[N];

void dfs(int cur, int par){
    Par[cur]=par;
    dep[cur]=dep[par]+1;
    for(int x: gr[cur]){
        if(x!=par){
            dfs(x, cur);
        }
    }

}

int LCA(int p, int q){
    if(p==q) return p;

    while(dep[p]!=dep[q]){
        if(dep[p]>dep[q]) p = Par[p];
        else q = Par[q];
    }

    while(p!=q){
        p = Par[p];
        q = Par[q];
    }

    return p;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    dfs(1, 0);

    cout << LCA(5, 2);

    return 0;
}