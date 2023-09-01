#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int>* g;

public:
    Graph(int v){
        this->V = v;
        this->g = new list<int>[v];
    }

    void addEdge(int u, int v, bool isUnDir=true){
        g[u].push_back(v);
        if(isUnDir) g[v].push_back(u);
    }

    void dfs_helper(int s, bool* visited){
        visited[s]=true;
        cout << s << " ";
        for(auto adj: g[s]){
            if(!visited[adj]){
                dfs_helper(adj, visited);
            }
        }
    }
    void dfs(int s){
        bool* visited = new bool[V]{0};
        dfs_helper(s, visited);
    }

    

};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);

    g.dfs(0);

    return 0;
}