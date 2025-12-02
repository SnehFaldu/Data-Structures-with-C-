// DSC_040_question.cpp
// 40. Common elements in all rows of a given matrix
// Use hashmap counting occurrences across rows.

#include <bits/stdc++.h>
using namespace std;

vector<int> commonInAllRows(vector<vector<int>>& mat) {
    int n=mat.size();
    unordered_map<int,int> cnt;
    for (int i=0;i<n;++i) {
        unordered_set<int> seen;
        for (int x: mat[i]) {
            if (!seen.count(x)) {
                cnt[x]++;
                seen.insert(x);
            }
        }
    }
    vector<int> res;
    for (auto &p: cnt) if (p.second == n) res.push_back(p.first);
    sort(res.begin(), res.end());
    return res;
}

int main(){
    vector<vector<int>> mat = {{1,2,1,4,8},{3,7,8,5,1},{8,7,7,3,1},{8,1,2,7,9}};
    auto v = commonInAllRows(mat);
    cout << "Common: ";
    for (int x: v) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
