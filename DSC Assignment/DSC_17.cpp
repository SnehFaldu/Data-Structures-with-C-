// Problem: Find median of two sorted arrays of different sizes.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a = {1, 3};
    vector<int> b = {2};
    vector<int> c(a);
    c.insert(c.end(), b.begin(), b.end());
    sort(c.begin(), c.end());

    int n = c.size();
    double median;
    if (n % 2 == 0)
        median = (c[n/2 - 1] + c[n/2]) / 2.0;
    else
        median = c[n/2];

    cout << "Median: " << median;
}

