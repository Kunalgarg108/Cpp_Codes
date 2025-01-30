#include <bits/stdc++.h>
using namespace std;

void MST(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(V, 0);  
    vector<pair<int, int>> MST;  
    pq.push({0, {0, -1}});  
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if (vis[node] == 1) continue;

        vis[node] = 1;
        sum =sum+ wt;
        if (parent != -1) {
            MST.push_back({parent, node});
        }
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edWt = it[1];
            if (!vis[adjNode]) {
                pq.push({edWt, {adjNode, node}});
            }
        }
    }
    cout << "MST edges:\n";
    for (auto edge : MST) {
        cout <<"("<< edge.first << "," << edge.second <<")"<< endl;
    }
    cout<<"Minimum sum of weight is:" <<sum<<endl;
    return;
}
int main() {
    int V = 8;
    vector<vector<int>> edges = {{0, 1, 2},{0, 3, 9}, {1, 4, 7},{1, 2, 5}, {2, 5, 6}, {3, 4, 11},{3,6,2},{4,5,1},{4,7,5},{6,7,10},{5,7,3}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }
    MST(V, adj);

    return 0;
}