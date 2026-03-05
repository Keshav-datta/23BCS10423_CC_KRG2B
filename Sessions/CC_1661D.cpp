#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    vector<long long> target(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> target[i];
    }

    vector<long long> startEffect(n + 3, 0);
    vector<long long> slopeEffect(n + 3, 0);

    long long operations = 0;
    long long currentAdd = 0;
    long long currentSlope = 0;

    for (int i = 1; i <= n; i++) {

        currentAdd += startEffect[i];
        currentSlope += slopeEffect[i];

        currentAdd += currentSlope;

        long long currentValue = currentAdd;

        if (currentValue < target[i]) {

            long long need = target[i] - currentValue;
            operations += need;

            currentAdd += need;
            currentSlope += need;

            if (i + k <= n) {
                slopeEffect[i + k] -= need;
                startEffect[i + k] -= need * k;
            }
        }
    }

    cout << operations << "\n";
}
