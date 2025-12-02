// DSC_008_question.cpp Find Largest Sum Contiguous Subarray (Kadane’s Algorithm)
#include <iostream>
using namespace std;

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = arr[0], currSum = arr[0];
    for (int i = 1; i < n; i++) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }

    cout << "Maximum subarray sum: " << maxSum;
}

