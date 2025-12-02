// DSC_039_question.cpp
// 39. Kth smallest element in a row-column wise sorted matrix
// Use binary search on value range (works when rows are sorted).

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& mat, int k) {
    int n=mat.size(), m=mat[0].size();
    int lo = mat[0][0], hi = mat[n-1][m-1];
    while (lo < hi) {
        int mid = lo + (hi - lo)/2;
        long long cnt = 0;
        for (auto &row: mat) cnt += upper_bound(row.begin(), row.end(), mid) - row.begin();
        if (cnt < k) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main(){
    vector<vector<int>> mat = {{1,5,9},{10,11,13},{12,13,15}};
    cout << "Kth smallest (k=8): " << kthSmallest(mat, 8) << "\n"; // 13
    return 0;
}
