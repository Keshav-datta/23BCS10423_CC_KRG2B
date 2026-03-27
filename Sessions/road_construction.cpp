#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sizev;

int findParent(int node){
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

void Union(int a, int b, int &largest){

    a = findParent(a);
    b = findParent(b);

    if(a == b) return;

    if(sizev[a] < sizev[b])
        swap(a,b);

    parent[b] = a;
    sizev[a] += sizev[b];

    largest = max(largest, sizev[a]);
}

int main(){

    int n,m;
    cin >> n >> m;

    parent.resize(n+1);
    sizev.resize(n+1);

    for(int i=1;i<=n;i++){
        parent[i] = i;
        sizev[i] = 1;
    }

    int components = n;
    int largest = 1;

    while(m--){
        int a,b;
        cin >> a >> b;

        if(findParent(a) != findParent(b)){
            Union(a,b,largest);
            components--;
        }

        cout << components << " " << largest << endl;
    }
}
