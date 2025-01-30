#include<bits/stdc++.h>
using namespace std;

void DFS(int i,int vis[],vector<int> adj[],stack<int>& st){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            DFS(it,vis,adj,st);
        }
    }
    st.push(i);
    return;
}
int main()
{
    int arr[6][2]={{1,0},{1,2},{2,3},{3,4},{5,0},{5,4}};
    int vis[6]={0};
    vector<int> adj[6];
    for(int i=0;i<6;i++){
        adj[arr[i][0]].push_back(arr[i][1]);
    }
    stack<int> st;
    for(int i=0;i<6;i++){
        if(!vis[i]){
            DFS(i,vis,adj,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}