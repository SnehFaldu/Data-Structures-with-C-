// DSC_079_question.cpp
// 79. Minimum time required to rot all oranges (multi-source BFS)

#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& g){
    int n=g.size(), m=g[0].size();
    queue<pair<int,int>> q; int fresh=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(g[i][j]==2) q.push({i,j});
        else if(g[i][j]==1) fresh++;
    }
    int time=0;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty() && fresh>0){
        int sz=q.size(); bool progressed=false;
        for(int s=0;s<sz;s++){
            auto [r,c]=q.front(); q.pop();
            for(auto &d:dirs){
                int nr=r+d[0], nc=c+d[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && g[nr][nc]==1){
                    g[nr][nc]=2; fresh--; q.push({nr,nc}); progressed=true;
                }
            }
        }
        if(progressed) time++;
    }
    return fresh==0?time:-1;
}
int main(){
    vector<vector<int>> a{{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(a)<<"\n"; // 4
    return 0;
}
