// DSC_037_question.cpp
// 37. Find a specific pair in matrix (if matrix is row/col sorted, find pair with given sum)
// We'll flatten with two pointers on each row using min-heap method is heavier; here
// we assume matrix sorted row-major for simplicity and use two-pointer on flattened array.

#include <bits/stdc++.h>
using namespace std;

bool findPairInMatrix(const vector<vector<int>>& mat, int target) {
    vector<int> flat;
    for (auto &row: mat) for (int x: row) flat.push_back(x);
    sort(flat.begin(), flat.end()); // ensure sorted
    int i=0, j=flat.size()-1;
    while (i<j) {
        int s = flat[i]+flat[j];
        if (s==target) return true;
        if (s < target) ++i; else --j;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1,3,5},{2,4,8},{6,7,9}};
    cout << (findPairInMatrix(mat, 13) ? "Pair found\n" : "No pair\n");
    return 0;
}
