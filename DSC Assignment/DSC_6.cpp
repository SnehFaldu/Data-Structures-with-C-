// DSC_006_question.cpp  Find Union and Intersection of two sorted arrays
#include <iostream>
#include <set>
using namespace std;

int main() {
    int a[] = {1, 2, 4, 5, 6};
    int b[] = {2, 3, 5, 7};
    int n = 5, m = 4;

    set<int> uni, inter;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) uni.insert(a[i++]);
        else if (a[i] > b[j]) uni.insert(b[j++]);
        else {
            uni.insert(a[i]);
            inter.insert(a[i]);
            i++; j++;
        }
    }
    while (i < n) uni.insert(a[i++]);
    while (j < m) uni.insert(b[j++]);

    cout << "Union: ";
    for (auto x : uni) cout << x << " ";
    cout << "\nIntersection: ";
    for (auto x : inter) cout << x << " ";
}

