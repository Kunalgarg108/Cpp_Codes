#include<bits/stdc++.h>
using namespace std;
void Prim(vector<pair<int,int>> adj[],int V,int S){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,S});
    int sum=0;
    vector<int> vis(V,0);
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;
        if(vis[node]==1){
            continue;
        }
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            if(!vis[it.first])
                pq.push({it.second,it.first});
        } 
    }
    cout<<sum<<endl;
    return;
}
int main()
{
    vector<vector<int>> edges={{2,0,1},{4,0,3},{8,1,3},{3,1,2},{6,1,4},{5,3,4},{1,2,4},{9,2,5},{10,4,5}};
    int V=6;
    vector<pair<int,int>> adj[V];
    for(auto it:edges){
        adj[it[1]].push_back({it[2],it[0]});
        adj[it[2]].push_back({it[1],it[0]});
    }
    int S=0;
    Prim(adj,V,S);
}