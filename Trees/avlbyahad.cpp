#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    int height;
    node(int d){
        data=d;
        left=right=NULL;
        height=0;
    }
};
class avl{
    node*rotateright(node* n){
    node*x= n->left;
    node* t2=x->right;
    x->right=n;
    n->left=t2;
    x->height=max(getHeight(root->left), getHeight(root->right))+1;
    n->height=max(getHeight(root->left), getHeight(root->right))+1;
    return x;
}
node*rotateleft(node *n){
    node*x=n->right;
    node*y=x->left;
    x->left=n;
    n->right=y;
}
    node* inserthelper(node*root,node*  n){
        if(!root){
            root=n;
            return root;
        }
        if(root->data>n->data){
            root->right=inserthelper(root->right,n);
        }
        else if(root->data<n->data){
            root->left=inserthelper(root->left,n);
        }
        else{
            return root;
        }
        root->height=max(getHeight(root->left), getHeight(root->right))+1;
        int  b=getbalance(root);
        if(b>1&&n->data<root->left->data)
            return rotateright(root);
        if(b<-1&&n->data>root->right->data)
            return rotateleft(root);
        if(b>1&&n->data>root->left->data){
            root->left=rotateleft(root);
            return rotateright(root);}
        if(b<-1&&n->data<root->left->data){
            root->right=rotateright(root);
            return rotateleft(root);}
    }
    int getHeight(node* node){
        if(node == NULL){
            return 0;
        }
        return node->height;
    }
    int getbalance(node*n){
        return (getHeight(root->left)-getHeight(root->right));
    }
    public:
    node* root;
    avl():root(NULL){}
    
    void insert(int d){
        node* n=new node(d);
        root=inserthelper(root,n);
    }
};
