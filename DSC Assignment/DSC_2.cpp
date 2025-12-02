// DSC_002_question.cpp Find the maximum and minimum element in an array
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = INT_MIN, minVal = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    cout << "Max: " << maxVal << "\nMin: " << minVal;
}

