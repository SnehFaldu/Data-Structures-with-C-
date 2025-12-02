// Problem: Find median of two sorted arrays of equal size.

#include <iostream>
using namespace std;

int main() {
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    int n = 5;

    int i = 0, j = 0, count;
    int m1 = -1, m2 = -1;

    for (count = 0; count <= n; count++) {
        if (i == n) { m1 = m2; m2 = arr2[0]; break; }
        else if (j == n) { m1 = m2; m2 = arr1[0]; break; }

        if (arr1[i] <= arr2[j]) { m1 = m2; m2 = arr1[i++]; }
        else { m1 = m2; m2 = arr2[j++]; }
    }

    cout << "Median: " << (m1 + m2) / 2.0;
}

