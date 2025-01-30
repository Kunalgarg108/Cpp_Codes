#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int gap,i,j;
    for(gap=n/2;gap>=1;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            j=i-gap;
            while(j>=0 && arr[j]>temp){
                arr[j+gap]=arr[j];
                j=j-gap;
            }
            arr[j+gap]=temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}