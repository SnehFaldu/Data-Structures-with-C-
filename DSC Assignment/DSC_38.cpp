// DSC_038_question.cpp
// 38. Rotate matrix by 90 degrees (in-place for square matrix)

#include <bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>>& a) {
    int n=a.size();
    // transpose
    for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) swap(a[i][j], a[j][i]);
    // reverse each row
    for(int i=0;i<n;++i) reverse(a[i].begin(), a[i].end());
}

void printMat(const vector<vector<int>>& a){
    for(auto &r: a){ for(int x: r) cout<<x<<" "; cout<<"\n"; }
}

int main(){
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Before:\n"; printMat(a);
    rotate90(a);
    cout<<"After 90 deg clockwise:\n"; printMat(a);
    return 0;
}
