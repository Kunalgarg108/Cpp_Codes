#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
void Heapify(vector<int>& arr,int i,int n){
    int l=2*i+1;
    int r=2*i+2;
    int larg=i;
    if(l<n && arr[l]>arr[larg]){
        larg=l;
    }
    if(r<n && arr[r]>arr[larg]){
        larg=r;
    }
    if(larg!=i){
        swap(arr[i],arr[larg]);
        Heapify(arr,larg,n);
    }
}
void Built_heap(vector<int>& arr,int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,i,n);
    }
    return;
}
void Heapsort(vector<int>& arr,int n){
    Built_heap(arr,n);
    for(int i=n-1;i>=1;i--){
        swap(arr[0],arr[i]);
        Heapify(arr,0,i);
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
    Heapsort(arr,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0; 
}