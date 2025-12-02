// DSC_005_question.cpp Move all negative elements to one side
#include <iostream>
using namespace std;

int main() {
    int arr[] = {-1, 2, -3, 4, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j) swap(arr[i], arr[j]);
            j++;
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

