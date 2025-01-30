#include<bits/stdc++.h>
using namespace std;
int main()
{
    int V=6;
    vector<int> adj[V];
    int edge[7][2]={{0,1},{1,2},{2,3},{3,0},{0,4},{4,5},{3,5}};
    int noeghe=7;
    for(int i=0;i<noeghe;i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    for(int i=0;i<V;i++)
    {
        cout<<i<<"->";
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    

}