#include<bits/stdc++.h>
using namespace std;
double functvalue(int x2,int x,int cons,int val){
    return x2*val*val+x*val+cons;
}
int main()
{
    cout<<"Enter the coeff of x^2(positive):";
    int x2=0;
    cin>>x2;
    cout<<"Enter the coeff of x:";
    int x=0;
    cin>>x;
    cout<<"Enter the constant:";
    int cons=0;
    cin>>cons;
    cout<<"Enter the first range:";
    double l=0;
    cin>>l;
    cout<<"Enter the second range:";
    double r=0;
    cin>>r;
    while(r-l>0.000001){
        double mid1=l+((r-l)/3);
        double mid2=r-((r-l)/3);
        double fun1=functvalue(x2,x,cons,mid1);
        double fun2=functvalue(x2,x,cons,mid2);
        if(fun1>fun2){
            l=mid1;
        }
        else if(fun1<fun2){
            r=mid2;
        }
        else{
            l=mid1;
            r=mid2;
        }
    }
    double value=functvalue(x2,x,cons,l);
    cout<<"Minimum value of function is:"<<value;
}