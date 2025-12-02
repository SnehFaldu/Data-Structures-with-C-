// DSC_117_question.cpp
// 117. Flood fill algorithm (change connected component color)

#include <bits/stdc++.h>
using namespace std;
void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
    int old = image[sr][sc];
    if(old == newColor) return;
    int n=image.size(), m=image[0].size();
    function<void(int,int)> dfs = [&](int r,int c){
        if(r<0||r>=n||c<0||c>=m||image[r][c]!=old) return;
        image[r][c]=newColor;
        dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1);
    };
    dfs(sr,sc);
}
int main(){
    vector<vector<int>> img={{1,1,1},{1,1,0},{1,0,1}};
    floodFill(img,1,1,2);
    for(auto &row: img){ for(int x: row) cout<<x<<" "; cout<<"\n"; }
}
