// DSC_114_question.cpp
// 114. Detect Cycle in Undirected Graph using DFS (track parent)

#include <bits/stdc++.h>
using namespace std;
bool dfs(int u, int p, const vector<vector<int>>& adj, vector<int>& vis){
    vis[u]=1;
    for(int v: adj[u]){
        if(!vis[v]){
            if(dfs(v,u,adj,vis)) return true;
        } else if(v!=p) return true;
    }
    return false;
}
bool hasCycleUndirected(const vector<vector<int>>& adj){
    int n=adj.size(); vector<int> vis(n,0);
    for(int i=0;i<n;i++) if(!vis[i] && dfs(i,-1,adj,vis)) return true;
    return false;
}
int main(){
    vector<vector<int>> g = {{1,2},{0,2},{0,1}}; // triangle
    cout<<(hasCycleUndirected(g) ? "Cycle\n":"No Cycle\n");
}
