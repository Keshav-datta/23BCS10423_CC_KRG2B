#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {

        const long long MOD = 1000000007;

        long long left = 1;
        long long right = 1LL * n * min(a, b);

        long long gcdValue = __gcd(a, b);
        long long lcmValue = (1LL * a * b) / gcdValue;

        while(left < right) {

            long long mid = left + (right - left) / 2;

            long long count = mid / a + mid / b - mid / lcmValue;

            if(count < n)
                left = mid + 1;
            else
                right = mid;
        }

        return left % MOD;
    }
};

int main() {

    long long n, a, b;
    cin >> n >> a >> b;

    Solution obj;
    cout << obj.nthMagicalNumber(n, a, b) << endl;

    return 0;
}
