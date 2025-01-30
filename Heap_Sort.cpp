#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int lchild(int i){
    return 2*i+1;
}
int rchild(int i){
    return 2*i+2;
}
int parent(int i){
    return ((i-1)/2);
}

void heapify(int arr[],int n,int i){
    int l=lchild(i);
    int r=rchild(i);
    int largest=i;
    if(l<n && arr[l]>arr[i]){
        largest=l;
    }
    if(r<n && arr[r]>arr[i]){
        largest=r;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
    return;
}

void build_heap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}

void heapsort(int arr[],int n){
    build_heap(arr,n);
    for(int i=n-1;i>=1;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

int main()
{
    int arr[]{10,8,5,7,4,3};
    heapsort(arr,6);
    for(auto a:arr){
        cout<<a<<" ";
    }
    cout<<endl;
}