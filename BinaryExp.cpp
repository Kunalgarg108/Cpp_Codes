#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

int recursiveexp(int a,int b){
    if(b==0){
        return 1;
    }
    int res=recursiveexp(a,b/2);
    if(b&1){
        return (a*(res*1LL*res)%mod)%mod;
    }
    else{
        return (res*1LL*res)%mod;
    }
}

int Iterativeexp(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*1LL*a)%mod;
        }
        a=(a*1LL*a)%mod;
        b=b>>1;
    }
    return ans;
}
int main()
{
    cout<<recursiveexp(2,24)<<endl;
    cout<<Iterativeexp(21,18)<<endl;
}