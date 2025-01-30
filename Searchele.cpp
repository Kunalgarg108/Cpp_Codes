#include<bits/stdc++.h>
using namespace std;
void binary_search(vector<int> arr){
    int n=arr.size();
    int l=0;
    int r=n-1;
    while(l<r){
        int mid=(r-l)/2;
        if(mid>0 && mid<n-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            cout<<arr[mid];
            return;
        }
        if(arr[mid]>arr[l]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return;
}
void linear_search(vector<int> arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        if(arr[i]<arr[i+1]){
            continue;
        }
        else{
            cout<<arr[i];
            return;
        }
    }
    cout<<arr[n-1];
}


int main()
{
    int size;
    cout<<"Enter the size:";
    cin>>size;
    cout<<"Enter the elements:";
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    linear_search(arr);
    cout<<endl;
    binary_search(arr);
    return 0;
}