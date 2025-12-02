// DSC_009_question.cpp Minimize the maximum difference between tower heights
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k = 2;
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];

    int small = arr[0] + k;
    int big = arr[n - 1] - k;
    if (small > big) swap(small, big);

    for (int i = 1; i < n - 1; i++) {
        int subtract = arr[i] - k;
        int add = arr[i] + k;

        if (subtract >= small || add <= big) continue;

        if (big - subtract <= add - small)
            small = subtract;
        else
            big = add;
    }

    cout << "Minimum difference is " << min(ans, big - small);
}

