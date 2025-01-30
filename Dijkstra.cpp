#include<bits/stdc++.h>
using namespace std;
void Dijkstra(vector<pair<int,int>> adj[],int V,int S,vector<int>& dist){
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,S});
    dist[S]=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;
        for(auto itt:adj[node]){
            int adjnode=itt.first;
            int wtt=itt.second;
            if(wtt+wt<dist[adjnode]){
                dist[adjnode]=wt+wtt;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
}
int main()
{
    vector<vector<int>> edges={{2,0,1},{4,0,3},{8,1,3},{3,1,2},{6,1,4},{5,3,4},{1,2,4},{9,2,5},{10,4,5}};
    int V=6;
    vector<pair<int,int>> adj[V];
    for(auto it:edges){
        int wt=it[0];
        int node=it[1];
        int adjnode=it[2];
        adj[node].push_back({adjnode,wt});
        adj[adjnode].push_back({node,wt});
    }
    vector<int> dist(V,1e9);
    int S=0;
    Dijkstra(adj,V,S,dist);
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}