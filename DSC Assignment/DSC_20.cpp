// Problem: Find if there exists a triplet with sum = X.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {12, 3, 4, 1, 6, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X = 24;

    sort(arr, arr + n);
    bool found = false;

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == X) {
                cout << "Triplet: " << arr[i] << ", " << arr[l] << ", " << arr[r];
                found = true; break;
            } else if (sum < X) l++;
            else r--;
        }
        if (found) break;
    }

    if (!found) cout << "No triplet found";
}

