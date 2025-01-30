#include<bits/stdc++.h>
using namespace std;
int main()
{
    int matrix[7][7]={
        {0,1,1,0,0,0,0},
        {1,0,1,1,0,0,0},
        {1,1,0,1,0,0,0},
        {0,1,1,0,1,1,0},
        {0,0,1,1,0,0,1},
        {0,0,0,1,0,0,1},
        {0,0,0,0,1,1,0}
    };
    int visited[7]={0,0,0,0,0,0,0};
    queue<int> q;
    visited[0]=1;
    cout<<1;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int j=0;j<7;j++){
            if(matrix[node][j]==1 && visited[j]==0){
                cout<<j+1;
                visited[j]=1;
                q.push(j);
            }
        }    
    }
    return 0;
}