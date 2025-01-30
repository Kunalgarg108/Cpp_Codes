//KMP(Knuth Morris Pratt) Algorithm

#include<bits/stdc++.h>
using namespace std;

void ComputeLPS(vector<int> &LPS,string sub){
    int len=0;
    int i=1;
    while(i<sub.length()){
        if(sub[i]==sub[len]){
            len++;
            LPS[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=LPS[len-1];
            }
            else{
                i++;
            }
        }
    }
}

int main()
{
    cout<<"Enter the string"<<endl;
    string s;
    cin>>s;
    cout<<"Enter the substring"<<endl;
    string sub;
    cin>>sub;
    vector<int>result;
    vector<int> LPS(sub.length(),0);
    ComputeLPS(LPS,sub);
    int i=0;
    int j=0;
    while(i<s.length()){
        if(s[i]==sub[j]){
            i++;
            j++;
        }
        if(j==sub.length()){
            result.push_back(i-j+1);
            j=LPS[j-1];
        }
        else if(s[i]!=sub[j]){
            if(j!=0){
                j=LPS[j-1];
            }
            else{
                i++;
            }
        }

    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

}