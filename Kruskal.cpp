#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
public:
    DisjointSet(int V){
        rank.resize(V+1,0);
        parent.resize(V+1,0);
        for(int i=0;i<=V;i++){
            parent[i]=i;
        }
    }
    int FindRep(int u){
        if(parent[u]!=u){
            parent[u]=FindRep(parent[u]);
        }
        return parent[u];
    }
    void UnionbyRank(int u,int v){
        int x=FindRep(u);
        int y=FindRep(v);
        if(x==y){
            return;
        }
        if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else if(rank[x]<rank[y]){
            parent[x]=y;
        }
        else{
            parent[y]=x;
            rank[x]+=1;
        }
    }
};

void Kruskal(vector<vector<int>>& edges,int V, vector<pair<int,int>>& ans){
    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    for(auto it:edges){
        int wt=it[0];
        int node=it[1];
        int adjnode=it[2];

        if(ds.FindRep(node)!=ds.FindRep(adjnode)){
            ans.push_back({node,adjnode});
            ds.UnionbyRank(node,adjnode);
        }
    }
    return;
}

int main(){
    vector<vector<int>> edges={{2,0,1},{4,0,3},{8,1,3},{3,1,2},{6,1,4},{5,3,4},{1,2,4},{9,2,5},{10,4,5}};
    vector<pair<int,int>> ans;
    Kruskal(edges,6,ans);
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}