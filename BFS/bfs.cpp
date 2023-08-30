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


    void bfs(int src){
        bool *visited = new bool[this->V]{0};
        queue<int> q;
        q.push(src);
        visited[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for(auto adj: g[node]){
                if(!visited[adj]){
                    visited[adj]=true;
                    q.push(adj);
                }
            }

        }
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

    g.bfs(0);

    return 0;
}