// DSC_116_question.cpp
// 116. Minimum Step by Knight (BFS on board)

#include <bits/stdc++.h>
using namespace std;
int minKnightMoves(int N, pair<int,int> src, pair<int,int> dest){
    vector<vector<int>> dist(N, vector<int>(N, -1));
    int dr[8] = {2,2,-2,-2,1,1,-1,-1};
    int dc[8] = {1,-1,1,-1,2,-2,2,-2};
    queue<pair<int,int>> q; q.push(src); dist[src.first][src.second]=0;
    while(!q.empty()){
        auto [r,c]=q.front(); q.pop();
        if(r==dest.first && c==dest.second) return dist[r][c];
        for(int i=0;i<8;i++){
            int nr=r+dr[i], nc=c+dc[i];
            if(nr>=0 && nr<N && nc>=0 && nc<N && dist[nr][nc]==-1){
                dist[nr][nc]=dist[r][c]+1; q.push({nr,nc});
            }
        }
    }
    return -1;
}
int main(){ cout<<minKnightMoves(8, {0,0}, {7,7})<<"\n"; }
