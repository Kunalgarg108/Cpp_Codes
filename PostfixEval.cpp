#include<bits/stdc++.h>
using namespace std;
int cal(int op1,int op2,char sym);
int main()
{
    stack <int> a;
    string s;
    cout<<"Enter the postfix string";
    cin>>s;
    char sym;
    for(int i=0;i<s.length();i++){
        int op1,op2;
        int val;
        sym=s[i];
        if(sym!='+' && sym!='*' && sym!='/' && sym!='-'){
            a.push(sym-'0');
        }
        else{
            op2=a.top();
            a.pop();
            op1=a.top();
            a.pop();
            val=cal(op1,op2,sym);
            a.push(val);
        }
    }
    cout<<a.top()<<endl;
    a.pop();
    return 0;
}
int cal(int op1,int op2,char sym){
    switch(sym){
        case '+':
        return op1+op2;
        case '-':
        return op1-op2;
        case '*':
        return op1*op2;
        case '/':
        if(op2==0){
            cout<<"Invalid Input"<<endl;
            return 0;
        }
        return op1/op2;
        default:
        cout<<"Error"<<endl;
        return 0;
    }
}