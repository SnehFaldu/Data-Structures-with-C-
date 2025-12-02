// DSC_058_question.cpp
// 58. The celebrity Problem (find person known by everyone but knows no one).
// Input: knows(i,j) function suitable for small examples.

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> M;
bool knows(int a,int b){ return M[a][b]; }

int findCelebrity(int n){
    int cand=0;
    for(int i=1;i<n;i++) if(knows(cand,i)) cand=i;
    for(int i=0;i<n;i++){
        if(i==cand) continue;
        if(knows(cand,i) || !knows(i,cand)) return -1;
    }
    return cand;
}

int main(){
    M = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    }; // person 1 is celebrity
    cout<<"Celebrity: "<<findCelebrity(3)<<"\n";
    return 0;
}
