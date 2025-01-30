#include<bits/stdc++.h>
using namespace std;

double power(int x,int n){
    if(n==0){
        return 1;
    }
    double y=1;
    while(n>0){
        if(n&1){
            y=y*x;
        }
        x=x*x;
        n=n>>1;
    }
    return y;
}

int main()
{
    int x=6;
    int n=5;
    cout<<power(x,n);
}