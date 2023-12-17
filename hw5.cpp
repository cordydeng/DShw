#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left,*right;
};

node* Search(node* n,int target);
void LevelOrder(node* ptr);
queue<node*> lo;

int main(void){
    int in=0;
    vector<int> input;
    node* root=new node;
    while((cin>>in)){
        input.push_back(in);
        if(cin.peek()=='\n'){
            break;
        }
    }
    queue<node*> tree;
    root->data=input[0];
    root->left=NULL;
    root->right=NULL;
    tree.push(root);
    for(int i=1;i<input.size();i++){
        node* n=tree.front();
        tree.pop();
        if(i<input.size()){
            node* l=new node;
            l->data=input[i++];
            l->left=NULL;
            l->right=NULL;
            n->left=l;
            tree.push(n->left);
        }
        if(i<input.size()){
            node* l=new node;
            l->data=input[i];
            l->left=NULL;
            l->right=NULL;
            n->right=l;
            tree.push(n->right);
        }
    }
    //LevelOrder(root);
    int change=0;
    node* current=root;
    queue<node*> reverse;
    while(cin>>change){
        node* t=Search(current,change);
        //cout<<t->data<<"\n";
        reverse.push(t);
        while(!reverse.empty()){
            node* now=reverse.front();
            reverse.pop();
            if(now){
                node* temp=now->left;
                now->left=now->right;
                now->right=temp;
                if(now->left){
                    reverse.push(now->left);
                }
                if(now->right){
                    reverse.push(now->right);
                }  
            }
        }
    }
    LevelOrder(root);
}

node * Search(node* n,int target){
    if(n){
        if(n->data==target){
            return n;
        }
        node* l = Search(n->left,target);
        if(l){
            return l;
        }
        node* r = Search(n->right,target);
        if(r){
            return r;
        }
    }
    return NULL;
}

void LevelOrder(node* ptr){
    if(!ptr){
        return;
    }
    lo.push(ptr);
    while(!lo.empty()){
        ptr=lo.front();
        lo.pop();
        if(ptr){
            cout<<ptr->data<<" ";
            if(ptr->left){
                lo.push(ptr->left);
            }
            if(ptr->right){
                lo.push(ptr->right);
            }
        }
        else{
            lo.pop();
        }
    }
}