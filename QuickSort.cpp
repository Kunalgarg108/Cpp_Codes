#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
int partation(vector<int>& arr,int p,int r){
    int pivot=arr[r];
    int j=p-1;
    for(int i=p;i<r;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[r]);
    return j+1;
}
void QuickSort(vector<int>& arr,int p,int r){
    if(p<r){
        int q=partation(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
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
    QuickSort(arr,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i];
    // }
    return 0;  
}