#include<iostream>
using namespace std;
int main(){
    int a,r,a1,a2;
    int count=0;
    cout<<"Enter the amount you want:";
    cin>>a;
    if(a>100){
       r=a%100;
       while(a>0){
        a=a-100;
        count++;
       }  
    }
    cout<<"Number of 100 rupees notes:"<<count-1<<endl;
    if(r>=50){
        r=r-50;
        cout<<"number of 50 rupees notes:1"<<endl;
    }
    if(r>=20 && r<50){
      r=r-20;
      if(r>=20){
        r=r-20;
        cout<<"number of 20 rupees notes:2"<<endl;
      }
      else{
        cout<<"number of 20 rupees notes:1"<<endl;
      }  
    }
    if(r>=10 && r<20){
        r=r-10;
        cout<<"number of 10 rupees notes:1"<<endl;
    }
    return 0;
}