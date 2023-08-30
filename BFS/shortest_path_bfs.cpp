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


    void bfs(int u, int v=-1){
        bool *visited = new bool[this->V]{0};
        int *dist = new int[this->V]{0};
        int *parent = new int[this->V];
        queue<int> q;
        q.push(u);
        visited[u]=1;
        dist[u]=0;
        parent[u]=u;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for(auto adj: g[node]){
                if(!visited[adj]){
                    visited[adj]=true;
                    q.push(adj);
                    dist[adj]=dist[node]+1;
                    parent[adj]=node;
                }
            }

        }

        //print shortest path
        cout<< "\nShortest path is : \n";
        for(int v=0; v<V; v++){
            cout<< v << ":" << dist[v] << endl;
        }
        if(v!=-1){
            cout << "Distance from v to u: ";
            while(v!=u){
                cout << v << " ";
                v = parent[v];
            }
            cout << u << '\n';
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

    g.bfs(0, 5);

    return 0;
}