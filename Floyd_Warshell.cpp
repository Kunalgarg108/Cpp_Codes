#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> edges={{2,0,1},{4,0,3},{8,1,3},{3,1,2},{6,1,4},{5,3,4},{1,2,4},{9,2,5},{10,4,5}};
    int V=6;
    vector<vector<int>> ans(V,vector<int> (V,1e8));
    for(int i=0;i<V;i++){
        ans[i][i]=0;
    }
    for(auto it:edges){
        ans[it[1]][it[2]]=it[0];
        ans[it[2]][it[1]]=it[0];

    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(ans[i][k]+ans[k][j]<ans[i][j]){
                    ans[i][j]=ans[i][k]+ans[k][j];
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}