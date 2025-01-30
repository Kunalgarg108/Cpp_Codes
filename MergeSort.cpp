#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
void Merge(vector<int>& arr,int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    vector<int> arr1(n1+1);
    vector<int> arr2(n2+1);
    arr1[n1]=INT_MAX;
    arr2[n2]=INT_MAX;
    for(int i=0;i<n1;i++){
        arr1[i]=arr[p+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[q+1+i];
    }
    int x=0;
    int y=0;
    for(int i=p;i<=r;i++){
        if(arr1[x]>arr2[y]){
            arr[i]=arr2[y++];
        }
        else{
            arr[i]=arr1[x++];
        }
    }
    return;
}
void Mergesort(vector<int>& arr,int p,int r){
    if(p<r){
        int q=p+(r-p)/2;
        Mergesort(arr,p,q);
        Mergesort(arr,q+1,r);
        Merge(arr,p,q,r);
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
    auto start = high_resolution_clock::now();
    Mergesort(arr,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i];
    // }
}