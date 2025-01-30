
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d):data(d),left(NULL),right(NULL){}
};
TreeNode* Insert(TreeNode* root,int val){
    if(root==NULL){
        root=new TreeNode(val);
        return root;
    }
    if(val<root->data){
        root->left=Insert(root->left,val);
    }
    else if(val>root->data){
        root->right=Insert(root->right,val);
    }
    return root;

}

void Preorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

TreeNode* Delete(TreeNode* root,int val){
    if(root==NULL){
        return root;
    }
    if(val<root->data){
        root->left=Delete(root->left,val);
    }
    else if(val>root->data){
        root->right=Delete(root->right,val);
    }
    else if(root->data==val){
        if(root->left==NULL){
            TreeNode* temp=root->right;
            delete(root);
            return temp;
        }
        if(root->right==NULL){
            TreeNode* temp=root->left;
            delete(root);
            return temp;
        }
    }
    return root;
}

void Search(TreeNode* root,int val){
    if(root==NULL){
        cout<<"Don't Exist"<<endl;
        return;
    }
    if(root->data>val){
        Search(root->left,val);
    }
    else if(root->data<val){
        Search(root->right,val);
    }
    else{
        cout<<"Fount it"<<endl;
    }
    
}

int main()
{
    int size;
    cout<<"Enter the size:";
    cin>>size;
    cout<<"Enter the elements"<<endl;
    TreeNode* root=NULL;
    for(int i=0;i<size;i++){
        int val;
        cin>>val;
        root=Insert(root,val);
    }
    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    cout<<"Enter the element:";
    int val2;
    cin>>val2;
    Search(root,val2);
    cout<<"Enter the deleted element:";
    int del;
    cin>>del;
    root=Delete(root,del);
    Inorder(root);
}