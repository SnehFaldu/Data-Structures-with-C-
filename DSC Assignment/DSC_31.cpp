// DSC_031_question.cpp
// 31. Spiral traversal on a Matrix
// (Repeat if you want this as a separate file; included earlier)
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    int top=0, bottom=a.size()-1, left=0, right=a[0].size()-1;
    vector<int> out;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;++j) out.push_back(a[top][j]);
        ++top;
        for(int i=top;i<=bottom;++i) out.push_back(a[i][right]);
        --right;
        if(top<=bottom){ for(int j=right;j>=left;--j) out.push_back(a[bottom][j]); --bottom; }
        if(left<=right){ for(int i=bottom;i>=top;--i) out.push_back(a[i][left]); ++left; }
    }
    for(int x:out) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
