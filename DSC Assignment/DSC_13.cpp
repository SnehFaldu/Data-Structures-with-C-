// Problem: Partition array into three parts:


#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
    int lowVal = 14, highVal = 20;

    int start = 0, end = n - 1, i = 0;
    while (i <= end) {
        if (arr[i] < lowVal) swap(arr[i++], arr[start++]);
        else if (arr[i] > highVal) swap(arr[i], arr[end--]);
        else i++;
    }

    for(int k = 0; k < n; k++) cout << arr[k] << " ";
}


