#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.size();
    long long ans = 0;

    if (k == 0) {
        long long zeroCount = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeroCount++;
            } else {
                ans += zeroCount * (zeroCount + 1) / 2;
                zeroCount = 0;
            }
        }

        ans += zeroCount * (zeroCount + 1) / 2;
    } 
    else {
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }

        int m = pos.size();

        for (int i = 0; i + k - 1 < m; i++) {

            int leftOne = pos[i];
            int rightOne = pos[i + k - 1];

            int leftLimit;
            if (i == 0) leftLimit = -1;
            else leftLimit = pos[i - 1];

            int rightLimit;
            if (i + k >= m) rightLimit = n;
            else rightLimit = pos[i + k];

            long long leftChoices = leftOne - leftLimit;
            long long rightChoices = rightLimit - rightOne;

            ans += leftChoices * rightChoices;
        }
    }

    cout << ans;

    return 0;
}
