#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x=8767865;
    long long y=18;
    int p=29988;
    long long ans=1;
    while(y>0){
        ans=ans%p;
        if(y&1){
            ans=(ans*x)%p;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    cout<<(ans%p+p)%p;
}