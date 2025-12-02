// Problem: Find the length of the smallest subarray with sum > x

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 4, 45, 6, 0, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 51;

    int start = 0, end = 0, currSum = 0, minLen = n + 1;

    while (end < n) {
        while (currSum <= x && end < n)
            currSum += arr[end++];

        while (currSum > x && start < n) {
            minLen = min(minLen, end - start);
            currSum -= arr[start++];
        }
    }

    cout << "Smallest subarray length: " << minLen;
}


