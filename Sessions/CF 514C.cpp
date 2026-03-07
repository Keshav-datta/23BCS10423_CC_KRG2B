#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    set<string> memory;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        memory.insert(s);
    }

    while (m--) {

        cin >> s;
        bool found = false;

        for (int i = 0; i < s.size(); i++) {

            char original = s[i];

            for (char c : {'a','b','c'}) {

                if (c == original) continue;

                s[i] = c;

                if (memory.count(s)) {
                    found = true;
                    break;
                }
            }

            s[i] = original;

            if (found) break;
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
