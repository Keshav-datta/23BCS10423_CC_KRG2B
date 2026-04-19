#include <bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--) {
        int max_val = 0;

        for(int len = 1; len <= k && i + len <= n; len++) {
            max_val = max(max_val, arr[i + len - 1]);
            dp[i] = max(dp[i], max_val * len + dp[i + len]);
        }
    }

    return dp[0];
}

int main() {
    int n, k;
    
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    cout << maxSumAfterPartitioning(arr, k) << endl;

    return 0;
}
