#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<string> names(n);
    
    for(int i = 0; i < n; i++)
        cin >> names[i];
    
    vector<int> adj[26];
    vector<int> indegree(26, 0);
    
    for(int i = 0; i < n - 1; i++)
    {
        string s = names[i];
        string t = names[i+1];
        
        int len = min(s.size(), t.size());
        bool found = false;
        
        for(int j = 0; j < len; j++)
        {
            if(s[j] != t[j])
            {
                adj[s[j]-'a'].push_back(t[j]-'a');
                indegree[t[j]-'a']++;
                found = true;
                break;
            }
        }
        
        if(!found && s.size() > t.size())
        {
            cout << "Impossible";
            return 0;
        }
    }
    
    queue<int> q;
    
    for(int i = 0; i < 26; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> topo;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        topo.push_back(node);
        
        for(auto it : adj[node])
        {
            indegree[it]--;
            
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    
    if(topo.size() != 26)
    {
        cout << "Impossible";
        return 0;
    }
    
    for(auto it : topo)
        cout << char(it + 'a');
    
    return 0;
}
