#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<bool> used(n, false);
        vector<long long> answer;

        long long current_or = 0;

        for (int step = 0; step < n; step++) {

            int best_index = -1;
            long long best_value = current_or;

            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    long long new_or = current_or | nums[i];
                    if (new_or > best_value) {
                        best_value = new_or;
                        best_index = i;
                    }
                }
            }

            if (best_index == -1) break;

            used[best_index] = true;
            answer.push_back(nums[best_index]);
            current_or = best_value;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                answer.push_back(nums[i]);
            }
        }

        for (auto x : answer) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
