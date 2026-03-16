 #include <bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};

    sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b){
        return (a[1] - a[0]) > (b[1] - b[0]);
    });

    int initialEnergy = 0;
    int currentEnergy = 0;

    for(auto &t : tasks){

        int actual = t[0];
        int minimum = t[1];

        if(currentEnergy < minimum){
            initialEnergy += (minimum - currentEnergy);
            currentEnergy = minimum;
        }

        currentEnergy -= actual;
    }

    cout << initialEnergy << endl;

    return 0;
}
