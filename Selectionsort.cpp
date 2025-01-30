#include<iostream>
using namespace std;
void Selectionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int smallest=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[smallest])
            {
                smallest=j;
            }
        }
        int temp=a[smallest];
        a[smallest]=a[i];
        a[i]=temp;
    }
}
int main()
{
    int a[]={2,5,3,7,4,1,9,8};
    int n=8;
    Selectionsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}