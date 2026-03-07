#include <bits/stdc++.h>
using namespace std;

long long calculateReward(vector<vector<long long>> &tasks, int n) {
    sort(tasks.begin(), tasks.end());

    long long timeSpent = 0;
    long long totalReward = 0;

    for (int i = 0; i < n; i++) {

        long long duration = tasks[i][0];
        long long deadline = tasks[i][1];

        timeSpent += duration;

        totalReward += (deadline - timeSpent);
    }

    return totalReward;
}

int main() {

    int n = 3;

    vector<vector<long long>> tasks = {
        {6, 10},
        {8, 15},
        {5, 12}
    };

    long long result = calculateReward(tasks, n);

    cout << result;

    return 0;
}
