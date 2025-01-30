#include<bits/stdc++.h>
using namespace std;
int main()
{
    int V = 6;
    vector<int> adj[V];
    int edge[7][2] = {{0,1}, {1,2}, {2,3}, {3,0}, {0,4}, {4,5}, {3,5}};
    int noeghe = 7;

    for(int i = 0; i < noeghe; i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    int vis[6] = {0};
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int y=q.front();
        q.pop();
        cout<<y<<" ";
        for(auto s:adj[y]){
            if(vis[s]==0){
                q.push(s);
                vis[s]=1;
            }
        }
    }
    return 0;
}