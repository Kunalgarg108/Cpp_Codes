#include<bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size:";
    cin>>size;
    int a[size];
    cout<<"Enter the elements:";
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    cout<<"Enter the target element:";
    int target=0;
    cin>>target;
    int l=0;
    int r=size-1;
    while(l<=r){
        int mid1=l+((r-l)/3);
        int mid2=r-((r-l)/3);
        if(a[mid1]==target || a[mid2]==target){
            cout<<"Found element";
            break;
        }
        else if(a[mid1]>target){
            r=mid1-1;
        }
        else if(a[mid2]<target){
            l=mid2+1;
        }
        else{
            l=mid1+1;
            r=mid2-1;
        }
    }
}