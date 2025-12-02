// DSC_010_question.cpp Minimum number of jumps to reach end of array
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int jumps = 0, farthest = 0, currentEnd = 0;

    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + arr[i]);
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    cout << "Minimum jumps: " << jumps;
}

