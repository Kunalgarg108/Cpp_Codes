#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6][2]={{1,0},{1,2},{2,3},{3,4},{5,0},{5,4}};
    int vis[6]={0};
    vector<int> adj[6];
    for(int i=0;i<6;i++){
        adj[arr[i][0]].push_back(arr[i][1]);
    }
    queue<int> q;
    int indegree[6]={0};
    for(int i=0;i<6;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<6;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return 0;
}