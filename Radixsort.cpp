#include<bits/stdc++.h>
using namespace std;
void Sort(vector<int>& arr,int n,int pos){
    vector<int> count(10,0);
    for(int i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    vector<int> brr(n,0);
    for(int i=n-1;i>=0;i--){
        brr[count[(arr[i]/pos)%10]-1]=arr[i];
        count[(arr[i]/pos)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=brr[i];
    }
    return;
}
void RadixSort(vector<int>& arr,int n){
    int maxi=*max_element(arr.begin(),arr.end());
    for(int pos=1;maxi/pos>0;pos*=10){
        Sort(arr,n,pos);
    }
    return;
}
int main()
{
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    RadixSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}