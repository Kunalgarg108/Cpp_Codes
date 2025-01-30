#include<bits/stdc++.h>
using namespace std;
void Dfs(int i,int arr[7][7],int visited[]){
    cout<<i;
    visited[i]=1;
    for(int j=0;j<7;j++){
        if(arr[i][j]==1 && visited[j]==0){
            Dfs(j,arr,visited);
        }
    }
    return;
}
int main()
{
    int visited[7]={0,0,0,0,0,0,0};
    int arr[7][7]={
        {0,1,1,0,0,0,0},
        {1,0,1,1,0,0,0},
        {1,1,0,1,0,0,0},
        {0,1,1,0,1,1,0},
        {0,0,1,1,0,0,1},
        {0,0,0,1,0,0,1},
        {0,0,0,0,1,1,0}
    };
    Dfs(0,arr,visited);
}