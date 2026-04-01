#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    if(n <= 2) {
        cout << n;
        return 0;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        map<pair<int,int>, int> mp;

        for(int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;

            mp[{dy, dx}]++;
            ans = max(ans, mp[{dy, dx}] + 1);
        }
    }

    cout << ans << endl;

    return 0;
}
