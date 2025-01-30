#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node *next;
};
struct Node* Insert(struct Node* list,int x);
void Splitlist(struct Node *list,struct Node **first,struct Node **second);
void display(struct Node *list);
void Mergesort(struct Node **list);
struct Node* Sortedlist(struct Node *first,struct Node *second);
int main()
{
    struct Node *list=NULL;
    list=Insert(list,70);
    list=Insert(list,60);
    list=Insert(list,50);
    list=Insert(list,40);
    list=Insert(list,10);
    list=Insert(list,20);
    list=Insert(list,30);
    Mergesort(&list);
    display(list);
    return 0;
}

struct Node* Insert(struct Node* list,int x){
    struct Node *nn;
    nn=new Node;
    nn->val=x;
    if(list==NULL){
        nn->next=NULL;
        return nn;
    }
    struct Node *last=list;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=nn;
    nn->next=NULL;
    return list;
}

void display(struct Node *list){
    while(list!=NULL){
        cout<<list->val<<" ";
        list=list->next;
    }
    cout<<endl;
    return;
}

void Mergesort(struct Node **list){
    struct Node *head=*list;
    struct Node *first=NULL;
    struct Node *second=NULL;
    if(head==NULL || head->next==NULL){
        return;
    } 
    Splitlist(head,&first,&second);
    Mergesort(&first);
    Mergesort(&second);
    *list=Sortedlist(first,second);
}

void Splitlist(struct Node *list,struct Node **first,struct Node **second){
    struct Node *fast=list->next;
    struct Node *slow=list;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    *first=list;
    *second=slow->next;
    slow->next=NULL;
    return;
}

struct Node* Sortedlist(struct Node *first,struct Node *second){
    struct Node *result=NULL;
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    if(first->val>second->val){
        result=second;
        result->next=Sortedlist(first,second->next);
    }
    else{
        result=first;
        result->next=Sortedlist(first->next,second);
    }
    return result;
}