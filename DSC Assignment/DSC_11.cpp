// Problem: Given an array of packet sizes and M students, distribute packets so that
// the difference between max and min chocolates is minimum.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 3;

    sort(arr, arr + n);

    int minDiff = INT_MAX;
    for(int i = 0; i + m - 1 < n; i++)
        minDiff = min(minDiff, arr[i + m - 1] - arr[i]);

    cout << "Minimum difference: " << minDiff;
}


