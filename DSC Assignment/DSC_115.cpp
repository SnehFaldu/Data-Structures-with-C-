// DSC_115_question.cpp
// 115. Search in a Maze: shortest path from source to target (0=free,1=blocked) using BFS

#include <bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>>& maze, pair<int,int> src, pair<int,int> dest){
    int n=maze.size(), m=maze[0].size();
    if(maze[src.first][src.second] || maze[dest.first][dest.second]) return -1;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q; q.push(src); dist[src.first][src.second]=0;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        auto [r,c]=q.front(); q.pop();
        if(r==dest.first && c==dest.second) return dist[r][c];
        for(auto &d: dirs){
            int nr=r+d[0], nc=c+d[1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]==0 && dist[nr][nc]==-1){
                dist[nr][nc]=dist[r][c]+1; q.push({nr,nc});
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> maze={{0,0,1},{0,0,0},{1,0,0}};
    cout<<shortestPath(maze, {0,0}, {2,2})<<"\n";
}
