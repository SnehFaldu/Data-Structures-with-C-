// DSC_113_question.cpp
// 113. Detect Cycle in Directed Graph using DFS (using colors)

#include <bits/stdc++.h>
using namespace std;
bool dfs(int u, vector<int>& color, const vector<vector<int>>& adj){
    color[u]=1; // visiting
    for(int v: adj[u]){
        if(color[v]==1) return true;
        if(color[v]==0 && dfs(v, color, adj)) return true;
    }
    color[u]=2; // visited
    return false;
}
bool hasCycleDirected(const vector<vector<int>>& adj){
    int n=adj.size(); vector<int> color(n,0);
    for(int i=0;i<n;i++) if(color[i]==0 && dfs(i,color,adj)) return true;
    return false;
}
int main(){
    vector<vector<int>> g = {{1},{2},{0}}; // cycle 0->1->2->0
    cout<<(hasCycleDirected(g) ? "Cycle\n":"No Cycle\n");
}
