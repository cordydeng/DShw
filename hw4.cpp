#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

void preorder(node* n);
void inorder(node* n);
void postorder(node* n);

int id=0;

int main(void){
    int NodeNum=0;
    cin>>NodeNum;
    int Input[NodeNum];
    for(int i=0;i<NodeNum;i++){
        cin>>Input[i];
    }
    
    queue<node*> tree;
    node* root,* current;
    root=new node;
    root->data=Input[0];
    root->left=NULL;
    root->right=NULL;
    tree.push(root);
    for(int i=1;i<NodeNum;i++){
        current=tree.front();
        tree.pop();
        if(i<NodeNum){
            node* n=new node;
            n->data=Input[i];
            n->left=NULL;
            n->right=NULL;
            current->left=n;
            tree.push(current->left);
        }
        if(++i<NodeNum){
            node* n=new node;
            n->data=Input[i];
            n->left=NULL;
            n->right=NULL;
            current->right=n;
            tree.push(current->right);
        }
    }
    preorder(root);
    cout<<endl;
    id=0;
    inorder(root);
    cout<<endl;
    id=0;
    postorder(root);
    
    return 0;
}

void inorder(node* n){
    if(n){
        inorder(n->left);
        if(n->data!=0){
            if(id==0){
                cout<<n->data;
            }
            else{
                cout<<" "<<n->data;
            }
            id++;
        }
        inorder(n->right);
    }
}

void preorder(node* n){
    if(n){
        if(n->data!=0){
            if(id==0){
                cout<<n->data;
            }
            else{
                cout<<" "<<n->data;
            }
            id++;
        }
        preorder(n->left);
        preorder(n->right);
    }
}

void postorder(node* n){
    if(n){
        postorder(n->left);
        postorder(n->right);
        if(n->data!=0){
            if(id==0){
                cout<<n->data;
            }
            else{
                cout<<" "<<n->data;
            }
            id++;
        }
    }
}