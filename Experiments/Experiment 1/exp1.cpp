#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    while(n > 1) {
        for(int i = 0; i < n-1; i++) {
            nums[i] = (nums[i] + nums[i+1]) % 10;
        }
        n--;
    }

    cout << nums[0] << endl;

    return 0;
}
