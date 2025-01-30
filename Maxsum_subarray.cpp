#include<bits/stdc++.h>
using namespace std;
void Double_forloop(vector<int> arr){
    int n=arr.size();
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        int subsum=arr[i];
        maxsum=max(subsum,maxsum);
        for(int j=i+1;j<n;j++){
            subsum+=arr[j];
            if(maxsum<subsum){
                maxsum=subsum;
            }
            if(subsum<0){
                break;
            }
        }
    }
    cout<<maxsum;
    return;
}
int maxcrossum(vector<int>& arr,int l,int m,int r){
    int left_sum=INT_MIN;
    int sum=0;
    for(int i=m;i>=l;i--){
        sum+=arr[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }

    int right_sum=INT_MIN;
    sum=0;
    for(int i=m+1;i<=r;i++){
        sum+=arr[i];
        if(sum>right_sum){
            right_sum=sum;
        }
    }
    return max(left_sum+right_sum,max(left_sum,right_sum));
}

int maxsum(vector<int>& arr,int l,int r){
    if(l>r){
        return INT_MIN;
    }
    if(l==r){
        return arr[l];
    }
    int m=(l+r)/2;
    return max(max(maxsum(arr,l,m),maxsum(arr,m+1,r)),maxcrossum(arr,l,m,r));
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
    Double_forloop(arr);
    cout<<endl;
    int max_sum=maxsum(arr,0,size-1);
    cout<<endl<<"Max Sum is:"<<max_sum;
    return 0;
}