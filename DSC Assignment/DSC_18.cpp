// Problem: Max profit by buying & selling at most 2 times.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(price)/sizeof(price[0]);

    vector<int> profit(n, 0);
    int max_price = price[n-1];

    for (int i = n - 2; i >= 0; i--) {
        max_price = max(max_price, price[i]);
        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        min_price = min(min_price, price[i]);
        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
    }

    cout << "Maximum profit: " << profit[n - 1];
}

