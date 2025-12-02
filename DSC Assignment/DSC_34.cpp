// DSC_034_question.cpp
// 34. Find row with maximum no. of 1's (each row sorted: 0...0 1...1)

#include <bits/stdc++.h>
using namespace std;
int rowWithMaxOnes(const vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int maxRow = -1;
    int j = m - 1;
    for (int i = 0; i < n; ++i) {
        while (j >= 0 && mat[i][j] == 1) --j;
        if (j < m - 1) maxRow = i;
    }
    return maxRow;
}

int main() {
    vector<vector<int>> mat = {{0,0,1,1},{0,1,1,1},{0,0,0,1}};
    cout << "Row with max 1s: " << rowWithMaxOnes(mat) << "\n"; // prints index
    return 0;
}
