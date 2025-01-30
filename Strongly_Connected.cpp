#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int> adj[],int vis[],int S,stack<int>& st){
    vis[S]=1;
    for(auto it:adj[S]){
        if(!vis[it]){
            DFS(adj,vis,it,st);
        }
    }
    st.push(S);
    return;
}

void DFS2(vector<int> adj[],int vis[],int S){
    vis[S]=1;
    for(auto it:adj[S]){
        if(!vis[it]){
            DFS2(adj,vis,it);
        }
    }
}
int main()
{
    vector<vector<int>> edges={{0,1},{1,2},{2,0},{1,3},{3,4}};
    int V=5;
    vector<int> adj[V];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }
    int vis[V]{0};
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            DFS(adj,vis,i,st);
        }
    }
    vector<int> adjRev[V];
    for(auto it:edges){
        adjRev[it[1]].push_back(it[0]);
    }
    for(int i=0;i<V;i++){
        vis[i]=0;
    }
    int count=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            count++;
            DFS2(adjRev,vis,node);
        }
    }
    cout<<count;
}