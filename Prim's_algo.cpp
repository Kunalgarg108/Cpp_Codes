#include<bits/stdc++.h>
using namespace std;


void MST(vector<pair<int,int>> adj[],int V){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    int vis[V]={0};
    pq.push({0,0,-1});
    int sum=0;
    vector<pair<int,int>> anslist;
    while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        int wt=node.first;
        int nbr=node.second.first;
        int parent=node.second.second;
        if(vis[nbr]==1){
            continue;
        }
        vis[nbr]=1;
        sum+=wt;
        if(parent!=-1){
            anslist.push_back({parent,nbr});
        }
        for(auto it:adj[nbr]){
            int adjnode=it.second;
            int weight=it.first;
            if(vis[adjnode]==0){
                pq.push({weight,adjnode,parent});
            }

        }
        for(auto it:anslist){
            cout<<it.first<<"-"<<it.second<<endl;
        }
    }
}
int main()
{
    int V=8;
    vector<vector<int>> edges={{0,1,2},{1,2,5},{0,3,9},{1,4,7},{3,4,11},{4,5,1},{3,6,2},{6,7,10},{5,7,3},{2,5,6}};
    vector<pair<int,int>> adj[V];
    for(auto it:edges){
        int part=it[1];
        int wt=it[2];
        adj[it[0]].push_back({part,wt});

        part=it[0];
        wt=it[2];
        adj[it[1]].push_back({part,wt});
    }
    MST(adj,V);
    return 0;
}