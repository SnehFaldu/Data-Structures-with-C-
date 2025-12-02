// DSC_003_question.cpp Find the "Kth" max and min element of an array
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    sort(arr, arr + n);

    cout << k << "rd smallest: " << arr[k - 1] << endl;
    cout << k << "rd largest: " << arr[n - k];
}

