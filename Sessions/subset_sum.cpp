#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    bool found = false;

    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;

        for(int j = 0; j < n; j++) {
            if(mask & (1 << j)) {
                sum += arr[j];
            }
        }

        if(sum == target) {
            found = true;
            cout << "Subset: ";
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) {
                    cout << arr[j] << " ";
                }
            }
            cout << endl;
        }
    }

    if(!found) cout << "No subset found";

    return 0;
}
