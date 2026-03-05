#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> freq(8001, 0);
        for (int x : arr) {
            freq[x]++;
        }

        int specialCount = 0;

        for (int start = 0; start < n; start++) {

            int sum = arr[start];

            for (int end = start + 1; end < n; end++) {

                sum += arr[end];

                if (sum > 8000) break;

                if (freq[sum] > 0) {
                    specialCount += freq[sum];
                    freq[sum] = 0; // avoid double counting
                }
            }
        }

        cout << specialCount << "\n";
    }
}
