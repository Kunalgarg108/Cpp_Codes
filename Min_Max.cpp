#include<bits/stdc++.h>
using namespace std;
void linear_search(vector<int> arr){
    int n=arr.size();
    int max_num=arr[0];
    int min_num=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max_num){
            max_num=arr[i];
        }
        if(arr[i]<min_num){
            min_num=arr[i];
        }
    }
    cout<<"Max element is: "<<max_num<<endl;
    cout<<"Min element is: "<<min_num;
    return;
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
    // binary_search(arr);
    return 0;
}