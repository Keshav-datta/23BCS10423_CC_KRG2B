#include <bits/stdc++.h>
using namespace std;

int find(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);

    for(auto &f : flights){
        int u = f[0];
        int v = f[1];
        int cost = f[2];
        adj[u].push_back({v, cost});
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<tuple<int,int,int>> q;
    q.push({0, src, 0});

    while(!q.empty()){
        auto [stops, city, cost] = q.front();
        q.pop();

        if(stops > k) continue;

        for(auto &neighbor : adj[city]){
            int nextCity = neighbor.first;
            int price = neighbor.second;
            int newCost = cost + price;

            if(newCost < dist[nextCity]){
                dist[nextCity] = newCost;
                q.push({stops + 1, nextCity, newCost});
            }
        }
    }

    if(dist[dst] == INT_MAX)
        return -1;

    return dist[dst];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> flights(m, vector<int>(3));

    for(int i = 0; i < m; i++){
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    int ans = find(n, flights, src, dst, k);

    cout << ans << endl;

    return 0;
}
