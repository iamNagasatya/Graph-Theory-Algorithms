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

    void printAdjList(){
        for(int v=0; v<this->V; v++){
            cout << v << ": ";
            for(auto node: g[v]){
                cout << node << ", ";
            }
            cout << '\n';
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
	g.printAdjList();

    return 0;
}