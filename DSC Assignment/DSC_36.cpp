// DSC_036_question.cpp
// 36. Maximum size rectangle (largest rectangle of 1's in a binary matrix)
// We build histogram row-by-row and compute largest rectangle in histogram.

#include <bits/stdc++.h>
using namespace std;

// largest rectangle in histogram
int lrh(vector<int>& h) {
    stack<int> st;
    int n=h.size(), maxA=0;
    for(int i=0;i<=n;++i){
        int cur = (i==n?0:h[i]);
        while(!st.empty() && cur < h[st.top()]) {
            int height = h[st.top()]; st.pop();
            int left = st.empty()? 0 : st.top()+1;
            int width = i - left;
            maxA = max(maxA, height*width);
        }
        st.push(i);
    }
    return maxA;
}

int maxRectangle(vector<vector<int>>& mat) {
    if (mat.empty()) return 0;
    int n = mat.size(), m = mat[0].size();
    vector<int> height(m,0);
    int best=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) height[j] = mat[i][j] ? height[j]+1 : 0;
        best = max(best, lrh(height));
    }
    return best;
}

int main(){
    vector<vector<int>> mat = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,0}
    };
    cout << "Max rectangle area: " << maxRectangle(mat) << "\n";
    return 0;
}
