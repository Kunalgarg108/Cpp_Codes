#include<bits/stdc++.h>
using namespace std;

int EEA(int a,int b,int *x,int *y){
    if(a==0){
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int gcd=EEA(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}

int main()
{
    int x,y,a,b;
    a=30;
    b=10;
    cout<<EEA(a,b,&x,&y)<<endl;
    cout<<x<<" ";
    cout<<y<<" ";
}