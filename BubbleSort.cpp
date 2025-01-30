#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        arr[i]=rand()%1000000000;
    }
    auto start=high_resolution_clock::now();
    for(int i=0;i<n;i++){
       bool flag=false; 
       for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1])
           swap(arr[j+1],arr[j]);
           flag=true;
       }
       if(flag==false){
           break;
       }
    }
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(end-start);
    cout<<duration.count();
    // for(int i=0;i<n;i++){
    //      cout<<arr[i];
    // }
    return 0;
}