#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rankv;

int findParent(int node){
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

void Union(int a, int b){

    a = findParent(a);
    b = findParent(b);

    if(a == b) return;

    if(rankv[a] < rankv[b])
        swap(a,b);

    parent[b] = a;

    if(rankv[a] == rankv[b])
        rankv[a]++;
}

bool isConnected(int a,int b){
    return findParent(a) == findParent(b);
}

int main(){

    int n = 4;
    vector<vector<int>> edges = {
        {1,1,2},
        {4,1,3},
        {3,2,3},
        {2,2,4},
        {5,3,4}
    };

    parent.resize(n+1);
    rankv.resize(n+1);

    for(int i=1;i<=n;i++){
        parent[i] = i;
        rankv[i] = 0;
    }

    sort(edges.begin(), edges.end());

    int mstWeight = 0;

    cout<<"Edges in MST:\n";

    for(auto edge : edges){

        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];

        if(!isConnected(u,v)){
            Union(u,v);
            mstWeight += wt;
            cout<<u<<" - "<<v<<" : "<<wt<<endl;
        }
    }

    cout<<"Total MST Weight = "<<mstWeight<<endl;
}
