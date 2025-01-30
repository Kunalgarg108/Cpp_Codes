#include<bits/stdc++.h>
using namespace std;
void Right_most_set_bit(int n){
    int rmsb = n & -n;
    bitset <8> binary(rmsb);
    cout<<binary<<endl;
}
void bits_On(int n){
    int count=0;
    while(n!=0){
        int rsbm = n & -n;
        n-=rsbm;
        count++;
    }
    cout<<"Number of one's is "<<count<<endl;
}
void Josephus_prob(int n){
    //n=2^x + l
    //sol=2*l + 1
    int i=1;
    while(i*2<=n){
        i=i*2;
    }
    int l=n-i;
    cout<<"Survivor is "<<2*l+1<<endl;
}
int main(){
    int pos=0;
    int mask=1<<pos;
    int n=24;
    //for bit On
    cout<<(n | mask)<<endl;
    //for bit off
    cout<<(n & ~mask)<<endl;
    //for bit toggling
    cout<<(n ^ mask)<<endl; 
    //for bit checking
    if(n & mask==0){
        cout<<"Bit is off"<<endl;
    }
    else{
        cout<<"Bit is On"<<endl;
    }

    //Uppercase to Lowercase
    cout<<char('b'&'_')<<endl;
    //Lowercase to Uppercase
    cout<<char('B'|' ')<<endl;
    
    //Count odd numbers function
    array<int,10> arr={1,2,3,4,5,6,7,8,9,10};
    int count=count_if(arr.begin(),arr.end(),[](int x){
        return (x&1);
    });
    cout<<"Odd Numbers:"<<count<<endl; 

    Right_most_set_bit(n);
    bits_On(n);
    Josephus_prob(8);
}