#include<bits/stdc++.h>
using namespace std;
void DFS(int s, int vis[], vector<int> adj[]) {
    vis[s] = 1;
    cout << s << " ";
    for(auto x : adj[s]) {
        if(vis[x] == 0) {
            DFS(x, vis, adj);
        }
    }
}

int main() {
    int V = 6;
    vector<int> adj[V];
    int edge[7][2] = {{0,1}, {1,2}, {2,3}, {3,0}, {0,4}, {4,5}, {3,5}};
    int noeghe = 7;

    for(int i = 0; i < noeghe; i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }

    int vis[6] = {0};
    DFS(0, vis, adj);
    return 0;
}
