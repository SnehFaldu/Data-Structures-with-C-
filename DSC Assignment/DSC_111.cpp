// DSC_111_question.cpp
// 111. Implement BFS algorithm

#include <bits/stdc++.h>
using namespace std;
void bfs(const vector<vector<int>>& adj, int src){
    int n = adj.size();
    vector<int> vis(n,0);
    queue<int> q; q.push(src); vis[src]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v: adj[u]) if(!vis[v]){ vis[v]=1; q.push(v); }
    }
    cout<<"\n";
}
int main(){
    vector<vector<int>> adj = {{1,4},{0,2,3},{1},{1},{0}};
    bfs(adj, 0);
}
