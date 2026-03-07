#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<long long> a(n+1);
        vector<long long> b(n+1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        vector<long long> prefix(n+1,0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + b[i];
        }

        vector<long long> count(n+2,0);
        vector<long long> extra(n+2,0);

        for (int i = 1; i <= n; i++) {

            long long total = a[i] + prefix[i-1];

            int pos = upper_bound(prefix.begin()+i, prefix.begin()+n+1, total) - prefix.begin();

            count[i]++;
            count[pos]--;

            if (pos <= n) {
                extra[pos] += total - prefix[pos-1];
            }
        }

        vector<long long> ans(n+1);
        long long running = 0;

        for (int i = 1; i <= n; i++) {
            running += count[i];
            ans[i] = running * b[i] + extra[i];
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
