// DSC_112_question.cpp
// 112. Implement DFS algorithm (recursive)

#include <bits/stdc++.h>
using namespace std;
void dfsRec(int u, const vector<vector<int>>& adj, vector<int>& vis){
    vis[u]=1; cout<<u<<" ";
    for(int v: adj[u]) if(!vis[v]) dfsRec(v, adj, vis);
}
int main(){
    vector<vector<int>> adj = {{1,2},{0,3},{0,3},{1,2}};
    vector<int> vis(adj.size(),0);
    dfsRec(0, adj, vis);
    cout<<"\n";
}
