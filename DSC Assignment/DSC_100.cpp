// DSC_100_question.cpp
// 100. Count number of occurrences of given string in 2D character array (walk in 8 directions, no revisit)

#include <bits/stdc++.h>
using namespace std;
int n,m;
string pat;
vector<string> g;
int dirs[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool vis[100][100];

int dfs(int r,int c,int idx){
    if(g[r][c]!=pat[idx]) return 0;
    if(idx==pat.size()-1) return 1;
    vis[r][c]=true;
    int cnt=0;
    for(auto &d: dirs){
        int nr=r+d[0], nc=c+d[1];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
            cnt += dfs(nr,nc,idx+1);
        }
    }
    vis[r][c]=false;
    return cnt;
}

int countOccurrences(vector<string> &board, string word){
    g=board; n=g.size(); m=g[0].size(); pat=word;
    memset(vis,0,sizeof(vis));
    int ans=0;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) ans += dfs(i,j,0);
    return ans;
}

int main(){
    vector<string> b = {"GEEKS", "FORG", "QUIZG", "EEKSF"};
    cout<<countOccurrences(b, "GFG")<<"\n"; // example
}
