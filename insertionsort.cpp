#include<iostream>
using namespace std;
int main()
{
    int key;
    int a[10];
    int x;
    cout<<"Enter the elements";
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<10;j++)
    {
        key=a[j];
        x=j-1;
        while(x>=0 && a[x]>key)
        {
            a[x+1]=a[x];
            x=x-1;  
        }
        a[x+1]=key;
    }
    cout<<"Arrenged array is\n";
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
}