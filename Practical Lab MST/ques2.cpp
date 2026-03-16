#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};

    int n = words.size();
    vector<int> mask(n,0);

    for(int i=0;i<n;i++){
        for(char c : words[i]){
            mask[i] |= (1 << (c-'a'));
        }
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){

            if((mask[i] & mask[j]) == 0){
                ans = max(ans, (int)words[i].length() * (int)words[j].length());
            }

        }
    }
    cout << ans << endl;
    return 0;
}
