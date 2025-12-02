// Problem: Combine adjacent elements to make array palindrome with min operations.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {11, 14, 15, 99};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = 0, j = n - 1, ops = 0;
    while (i < j) {
        if (arr[i] == arr[j]) {
            i++; j--;
        } else if (arr[i] < arr[j]) {
            arr[i + 1] += arr[i];
            i++; ops++;
        } else {
            arr[j - 1] += arr[j];
            j--; ops++;
        }
    }

    cout << "Minimum operations: " << ops;
}

