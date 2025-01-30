//Sieve of Eratosthenes
//TC:O(nlog(log(n)))

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100];
    for(int i = 0; i < 100; i++) {
        arr[i] = 1;
    }
    for(int i=2;i*i<100;i++){
        if(arr[i]==1){
            for(int j=i*i;j<100;j+=i){
                arr[j]=0;
            }
        }
    }
    for(int i=2;i<100;i++){
        if(arr[i]==1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
