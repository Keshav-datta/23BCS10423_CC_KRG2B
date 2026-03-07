// Football problem
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> goals;
    string team;

    for (int i = 0; i < n; i++) {
        cin >> team;
        goals[team]++;
    }

    string winner;
    int maxGoals = 0;

    for (auto it : goals) {
        if (it.second > maxGoals) {
            maxGoals = it.second;
            winner = it.first;
        }
    }

    cout << winner;

    return 0;
}
