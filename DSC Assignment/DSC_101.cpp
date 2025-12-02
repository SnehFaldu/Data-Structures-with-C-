// DSC_101_question.cpp
// 101. Search a Word in a 2D Grid of characters.

#include <bits/stdc++.h>
using namespace std;
int R, C;
string word;
vector<string> board;
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool used[100][100];

bool dfs(int r,int c,int idx){
    if(board[r][c] != word[idx]) return false;
    if(idx+1 == (int)word.size()) return true;
    used[r][c] = true;
    for(auto &d: dirs){
        int nr=r+d[0], nc=c+d[1];
        if(nr>=0 && nr<R && nc>=0 && nc<C && !used[nr][nc]){
            if(dfs(nr,nc,idx+1)){ used[r][c]=false; return true; }
        }
    }
    used[r][c]=false;
    return false;
}

bool exist(vector<string> &b, string w){
    board=b; word=w; R=b.size(); C=b[0].size();
    memset(used,0,sizeof(used));
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) if(dfs(i,j,0)) return true;
    return false;
}

int main(){
    vector<string> b = {"ABCE","SFCS","ADEE"};
    cout << (exist(b, "ABCCED") ? "Found\n" : "Not Found\n");
    cout << (exist(b, "SEE") ? "Found\n" : "Not Found\n");
    cout << (exist(b, "ABCB") ? "Found\n" : "Not Found\n");
}
