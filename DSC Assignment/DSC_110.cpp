// DSC_110_question.cpp
// 110. Create a Graph, print it (undirected adjacency list)

#include <bits/stdc++.h>
using namespace std;
struct Graph {
    int n;
    vector<vector<int>> adj;
    Graph(int n): n(n), adj(n) {}
    void addEdge(int u,int v){ adj[u].push_back(v); adj[v].push_back(u); }
    void print(){
        for(int i=0;i<n;++i){
            cout<<i<<": ";
            for(int v: adj[i]) cout<<v<<" ";
            cout<<"\n";
        }
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1); g.addEdge(0,4); g.addEdge(1,2); g.addEdge(1,3);
    g.print();
}
