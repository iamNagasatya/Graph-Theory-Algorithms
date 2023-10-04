#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

const int N = 1e5+1;

vector<int> gr[N];
int vis[N], indegree[N];



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
        indegree[y]++;
    }

    queue<int> Q;

    for(int v=1; v<=n; v++){
        if(indegree[v]==0){
            Q.push(v);
        }
    }

    while(!Q.empty()){
        int cur = Q.front();
        cout << cur << " ";
        Q.pop();

        for(int x : gr[cur]){
            indegree[x]--;
            if(indegree[x]==0){
                Q.push(x);
            }
        }
    }
    

    return 0;
}