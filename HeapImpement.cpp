#include<bits/stdc++.h>
using namespace std;
void Heapify(vector<int>& arr,int i,int n){
    int l=2*i+1;
    int r=2*i+2;
    int larg=i;
    if(l<n && arr[larg]<arr[l]){
        larg=l;
    }
    if(r<n && arr[larg]<arr[r]){
        larg=r;
    }
    if(larg!=i){
        swap(arr[larg],arr[i]);
        Heapify(arr,larg,n);
    }
    return;
}
void Build_heap(vector<int>& arr,int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,i,n);
    }
    return;
}

int main()
{
    int n=10;
    vector<int> arr(n);
    cout<<"Enter ten elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Build_heap(arr,n);
    cout<<"After build_heap call"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    swap(arr[0],arr[9]);
    Heapify(arr,0,n);
    cout<<"After removing root element"<<endl;
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int ele;
    cout<<"Enter the element to add in heap:";
    cin>>ele;
    arr[9]=ele;
    Heapify(arr,n-1,n);
    cout<<"After insertion of element"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}