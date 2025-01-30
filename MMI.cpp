#include<bits/stdc++.h>
using namespace std;
int EEA(int a,int b,int *x,int *y){
    if(a==0){
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int g=EEA(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return g;
}

int main()
{
    int x;
    int y;
    int a=3;
    int m=11;
    int g=EEA(a,m,&x,&y);
    if(g!=1){
        cout<<"Invalid";
    }
    else{
        cout<<((x%m)+m)%m;
    }
}