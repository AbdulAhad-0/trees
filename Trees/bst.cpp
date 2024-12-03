#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){data=d;
        left=NULL;
        right=NULL;}};
class BinarySearchTree{
    public:
    Node* root;
    BinarySearchTree(){
        root = NULL;
    }
    void insert(int data){
        Node* n = new Node(data);
        root = insertHelper(root,n);
    }
    Node* insertHelper(Node* root, Node* newNode){
        if(root == NULL){
            root = newNode;
            return root;
        }
        if(newNode->data<root->data)
            root->left=insertHelper(root->left,newNode);
        else
            root->right=insertHelper(root->right,newNode);
        return root;
    }
    void iterativeInsert(int data){
        Node* n = new Node(data);

        if(root == NULL){
            root = n;
            return;
        }
        Node* curr = root;
        Node* prev;
        while(curr != NULL){
            prev = curr;
            if(n->data < curr->data){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        if(n->data < prev->data){
            prev->left = n;
        }
        else{
            prev->right = n;
        }
    }
    void inorderTraversal(Node* root){
        if(root != NULL){
            inorderTraversal(root->left);
            cout<<", "<<root->data;
            inorderTraversal(root->right);
        }
    }
    void preorderTraversal(Node* root){
        if(root != NULL){
            cout<<", "<<root->data;
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
    void postorderTraversal(Node* root){
        if(root != NULL){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout<<", "<<root->data;
        }
    }
    bool search(int data){
        if(searchHelper(root,data)){
            cout<<data<<" found"<<endl;
            return true;
        }
        else{
            cout<<data<<" not found"<<endl;
            return false;
        }
    }
    bool searchHelper(Node* root ,int data){
        if(root == NULL){
            return false;
        }
        if(root->data == data){
            return true;
        }
        if(data < root->data){
            return searchHelper(root->left,data);
        }
        else{
            return searchHelper(root->right,data);
        }
    }
    Node* findMin(Node* root){
        if(root == NULL){
            return NULL;
        }
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }
    Node* findMax(Node* root){
        if(root == NULL){
            return NULL;
        }
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    void deleteNode(int data){
        if(search(data)){
        root = deleteHelper(root,data);
        }
        else{
        cout<<data<<" not found";
        }
    }
    Node* deleteHelper(Node* root, int data){
        if(root == NULL){
            return NULL;
        }
        if(data < root->data){
            root->left = deleteHelper(root->left,data);
        }
        else if(data > root->data){
            root->right = deleteHelper(root->right,data);
        }
        else{ // node found
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            //two child nodes
            Node* replace = findMin(root->right);
            root->data = replace->data;
            root->right = deleteHelper(root->right,replace->data);            
        }
        return root;
    }
  int findHeight(Node* root){
        if(root == NULL){
            return 0;
        }
        int hLeft = findHeight(root->left);
        int hRight = findHeight(root->right);
        if(hLeft > hRight){
            return hLeft + 1;
        }
        return hRight + 1;
    }
};
int main(){
    BinarySearchTree tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(5);
    tree.insert(9);
    tree.insert(1);
    tree.insert(2);
    tree.insert(7);
    // tree.iterativeInsert(8);
    // tree.iterativeInsert(3);
    // tree.iterativeInsert(5);
    // tree.iterativeInsert(9);
    // tree.iterativeInsert(1);
    // tree.iterativeInsert(2);
    // tree.iterativeInsert(7);
    //         8
    //     3       9
    // 1      5
    //   2      7
    tree.inorderTraversal(tree.root);
    cout<<endl;
    tree.preorderTraversal(tree.root);
    cout<<endl;
    tree.postorderTraversal(tree.root);
    cout<<endl;
    tree.search(9);
    tree.search(4);
    tree.search(5);
    tree.deleteNode(7);
    tree.inorderTraversal(tree.root);
    cout<<endl;
    tree.deleteNode(5);
    tree.inorderTraversal(tree.root);
    cout<<endl;
    cout<<tree.findHeight(tree.root);
    cout<<endl;
}