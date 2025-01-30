#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

int Height(Node* root){
    if(root==NULL){
        return 0;
    }
    cout<<root->data<<endl;
    int left=Height(root->left);
    int right=Height(root->right);
    return left>right?(left+1):(right+1);
}
int main(){
    Node* root = new Node(2);
    root->left = new Node(3);
    root->left->left= new Node(4);
    root->right= new Node(5);
    root->right->left=new Node(6);
    root->right->left->left=new Node(7);
    int h=Height(root);
    cout<<"Height of tree is:"<<h<<endl;
    return 0;
}
