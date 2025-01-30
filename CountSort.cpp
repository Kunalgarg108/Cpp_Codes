#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
void CountSort(vector<int>& arr,int l,int r,vector<int>& Sortedarr){
    int maximum=*max_element(arr.begin(),arr.end());
    vector<int> countarr(maximum+1,0);
    for(int i=0;i<r;i++){
        countarr[arr[i]]++;
    }
    for(int i=1;i<=maximum;i++){
        countarr[i]=countarr[i]+countarr[i-1];
    }
    for(int i=r-1;i>=0;i--){
        Sortedarr[countarr[arr[i]]-1]=arr[i];
        countarr[arr[i]]--;
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        arr[i]=rand()%1000000000;
    }
    vector<int> Sortedarr(n,0);
    auto start=high_resolution_clock::now();
    CountSort(arr,0,n,Sortedarr);
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<duration.count();
    // for(int i=0;i<n;i++){
    //     cout<<Sortedarr[i];
    // }

}