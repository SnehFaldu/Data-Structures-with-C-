// DSC_033_question.cpp
// 33. Find median in a row wise sorted matrix

#include <bits/stdc++.h>
using namespace std;
int findMedian(vector<vector<int>>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    int lo = INT_MAX, hi = INT_MIN;
    for (auto &row: mat) { lo = min(lo, row.front()); hi = max(hi, row.back()); }
    int desired = (r * c + 1) / 2;
    while (lo < hi) {
        int mid = lo + (hi - lo)/2;
        long long count = 0;
        for (auto &row: mat) count += upper_bound(row.begin(), row.end(), mid) - row.begin();
        if (count < desired) lo = mid + 1; else hi = mid;
    }
    return lo;
}

int main() {
    vector<vector<int>> m = {{1,3,5},{2,6,9},{3,6,9}};
    cout << "Median is: " << findMedian(m) << "\n";
    return 0;
}
