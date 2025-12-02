// DSC_035_question.cpp
// 35. Print elements in sorted order using row-column wise sorted matrix
// Use min-heap to merge rows (like merging sorted lists)

#include <bits/stdc++.h>
using namespace std;
struct Item { int val; int r; int c; };
struct Cmp { bool operator()(const Item& a, const Item& b) const { return a.val > b.val; } };

int main() {
    vector<vector<int>> mat = {{1,5,9},{2,6,10},{3,7,11}};
    priority_queue<Item, vector<Item>, Cmp> pq;
    for (int i=0;i<mat.size();++i) if (!mat[i].empty()) pq.push({mat[i][0], i, 0});
    vector<int> out;
    while(!pq.empty()) {
        auto it=pq.top(); pq.pop();
        out.push_back(it.val);
        if (it.c + 1 < mat[it.r].size()) pq.push({mat[it.r][it.c+1], it.r, it.c+1});
    }
    for (int x: out) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
