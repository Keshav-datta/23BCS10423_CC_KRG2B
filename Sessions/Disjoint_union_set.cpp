#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sizev;

int findParent(int node){
    if(parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}

void Union(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a != b){
        if(sizev[a] < sizev[b])
            swap(a,b);

        parent[b] = a;
        sizev[a] += sizev[b];
    }
}

int main(){

    int n, q;
    cin >> n >> q;   

    parent.resize(n+1);
    sizev.resize(n+1);

    for(int i=1;i<=n;i++){
        parent[i] = i;
        sizev[i] = 1;
    }

    while(q--){
        int u, v;
        cin >> u >> v;

        Union(u,v);
    }

    int a,b;
    cin >> a >> b;

    if(findParent(a) == findParent(b))
        cout<<"Connected\n";
    else
        cout<<"Not Connected\n";
}
