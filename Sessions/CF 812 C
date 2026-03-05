#include <bits/stdc++.h>
using namespace std;

int main() {
`  long long n, budget;
    cin >> n >> budget;

    vector<long long> basePrice(n);
    for (int i = 0; i < n; i++) {
        cin >> basePrice[i];
    }

    long long bestCount = 0;
    long long minCost = 0;

    long long left = 0, right = n;

    while (left <= right) {
        long long mid = (left + right) / 2;

        vector<long long> adjustedCost(n);

        for (int i = 0; i < n; i++) {
            adjustedCost[i] = basePrice[i] + (i + 1) * mid;
        }

        sort(adjustedCost.begin(), adjustedCost.end());

        long long total = 0;
        for (int i = 0; i < mid; i++) {
            total += adjustedCost[i];
        }

        if (total <= budget) {
            bestCount = mid;
            minCost = total;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << bestCount << " " << minCost << "\n";
}
