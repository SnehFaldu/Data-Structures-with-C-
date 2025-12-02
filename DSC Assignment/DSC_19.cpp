// Problem: Check if arr2 is subset of arr1.

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int n = 6, m = 4;

    unordered_set<int> s(arr1, arr1 + n);
    bool isSubset = true;
    for(int i = 0; i < m; i++) {
        if (s.find(arr2[i]) == s.end()) {
            isSubset = false; break;
        }
    }

    cout << (isSubset ? "Yes, subset" : "No, not subset");
}

