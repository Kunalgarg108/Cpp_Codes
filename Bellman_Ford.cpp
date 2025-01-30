#include<bits/stdc++.h>
using namespace std;
void Bellman(vector<vector<int>> edges,vector<int>& dist,int S,int V){
    dist[S]=0;
    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int wt=it[0];
            int node=it[1];
            int adjnode=it[2];
            if(dist[node]!=1e8 && wt+dist[node]<dist[adjnode]){
                dist[adjnode]=wt+dist[node];
            }
        }
    }
    return;
}
int main()
{
    vector<vector<int>> edges={{2,0,1},{4,0,3},{8,1,3},{3,1,2},{6,1,4},{5,3,4},{1,2,4},{9,2,5},{10,4,5}};
    int V=6;
    vector<int> dist(V,1e8);
    Bellman(edges,dist,0,V);
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }

}