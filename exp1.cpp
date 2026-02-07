// ---------- Brute Force ----------
class SolutionBrute {
public:
    int nthMagicalNumber(int n, int a, int b) {

        long long count = 0;
        long long num = 1;

        while (count < n) {
            if (num % a == 0 || num % b == 0) {
                count++;
            }
            num++;
        }

        return num - 1;
    }
};



// ---------- Optimal Approach ----------
class SolutionOptimal {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {

        long long lcm = (1LL * a * b) / gcd(a, b);

        long long low = 1;
        long long high = 1LL * n * min(a, b);
        long long ans = 0;

        while (low <= high) {

            long long mid = (low + high) / 2;

            long long count = mid / a + mid / b - mid / lcm;

            if (count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
