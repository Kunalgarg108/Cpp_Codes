#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};

void Insert(struct Node **list,int val);
void Insert_Hash(struct Node *Hash[],int key);
int Hash_Table(int key);
int Search(struct Node *list,int key);
int main()
{
    struct Node *Hash[10];
    for(int i=0;i<10;i++){
        Hash[i]=NULL;
    }
    Insert_Hash(Hash,12);
    Insert_Hash(Hash,15);
    Insert_Hash(Hash,27);
    Insert_Hash(Hash,39);
    Insert_Hash(Hash,41);
    Insert_Hash(Hash,44);
    Insert_Hash(Hash,48);
    Insert_Hash(Hash,49);
    Insert_Hash(Hash,52);
    Insert_Hash(Hash,57);
    Insert_Hash(Hash,64);
    Insert_Hash(Hash,69);
    Insert_Hash(Hash,99);
    int temp=Search(Hash[Hash_Table(49)],49);
    cout<<temp<<endl;
    return 0;
}

void Insert(struct Node **list,int x){
    struct Node *nn=NULL;
    nn=new Node;
    nn->val=x;
    nn->next=NULL;
    if(*list==NULL){
        *list=nn;
        return;
    }
    struct Node *last=*list;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=nn;
    return;
}

int Hash_Table(int key){
    return key%10;
}

void Insert_Hash(struct Node *Hash[],int key){
    int index=Hash_Table(key);
    Insert(&Hash[index],key);
}

int Search(struct Node *list,int key){
    while(list!=NULL){
        if(list->val==key){
            return list->val;
        }
        list=list->next;
    }
    return -1;
}