
#include <iostream>
#include <queue>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node *insertNode(Node *root,int data){
	if(root == NULL){
		root = new Node(data);
		return root;
	}
	
	queue<Node*> q;
	q.push(root);
	
	while(!q.empty()){
		Node *curr = q.front();
		q.pop();
		
		if(curr->left!=NULL){
			q.push(curr->left);
		}
		else{
			curr->left = new Node(data);
			return root;
		}
		
		if(curr->right!=NULL){
			q.push(curr->right);
		}
		else{
			curr->right = new Node(data);
			return root;
		}
	}
	
	return root;
	
}

void deleteDeepest(Node *root, Node *toBeDeleted){
	queue<Node*> q;
	Node *curr;
	q.push(root);
	
	while(!q.empty()){
		curr = q.front();
		q.pop();
		
		if(curr == toBeDeleted){
			curr = NULL;
			delete (toBeDeleted);
			return;
		}
		
		if(curr->right){
			if(curr->right == toBeDeleted){
				curr->right = NULL;
				delete (toBeDeleted);
				return;
			}
			q.push(curr->right);
		}
		
		if(curr->left){
			if(curr->left == toBeDeleted){
				curr->left = NULL;
				delete (toBeDeleted);
				return;
			}
			q.push(curr->left);
		}
	}
}

Node *deletion(Node *root,int data){
	if(root==NULL){
		return NULL;
	}
	
	if (root->left == NULL && root->right == NULL) {
        if (root->data == data)
            return NULL;
        else
            return root;
    }
    
    queue<Node*> q;
    q.push(root);
    Node *curr;
    Node *keynode;
    
    while(!q.empty()){
    	curr = q.front();
    	q.pop();
    	
    	if(curr->data == data){
    		keynode = curr;
		}
		if(curr->left){
			q.push(curr->left);
		}
		if(curr->right){
			q.push(curr->right);
		}
		
		
	}
	if(keynode!=NULL){
		int x = curr->data;
		keynode->data = x;
		deleteDeepest(root,curr);
	}
            
}

void inorder(Node* curr) {
    if(curr != NULL){
        inorder(curr->left);
        cout << curr->data << ' ';
        inorder(curr->right);
    }
}

void preorder(Node* curr) {
    if(curr != NULL){
        cout << curr->data << ' ';
        preorder(curr->left);
        preorder(curr->right);
    }
}

void postorder(Node* curr) {
    if(curr != NULL){
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << ' ';
    }
}

void levelOrderTraversal(Node *root){
	if(root!=NULL){
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			Node *curr = q.front();
			q.pop();
			cout<< curr->data << " ";
			if(curr->left){
				q.push(curr->left);
			}
			if(curr->right){
				q.push(curr->right);
			}
		}
	}
}

int maxDepth(Node *root){
	if(root==NULL){
		return 0;
	}
	int LDepth = maxDepth(root->left);
	int RDepth = maxDepth(root->right);
	
	return max(LDepth, RDepth) + 1;
}


int main() {
  
      // Constructing the binary tree
      //        10
    //        /    \ 
    //       11     9
    //      /      / \
    //     7      15   8
  
    // Node* root = new Node(10);
    // root->left = new Node(11);
    //   root->right = new Node(9);
    // root->left->left = new Node(7);
    // root->right->left = new Node(15);
    // root->right->right = new Node(8);
  
    // int key = 12;
    // root = InsertNode(root, key);
  
    //   // After insertion 12 in binary tree
    //   //          10
    // //        /    \ 
    // //       11     9
    // //      /  \   / \
    // //     7   12 15  8

    // inorder(root);

    Node* root = NULL;
    root = insertNode(root,10);
    root = insertNode(root,11);
    root = insertNode(root,9);
    root = insertNode(root,7);
    root = insertNode(root,15);
    root = insertNode(root,8);
    root = insertNode(root,12);
    inorder(root);
    cout<<endl;
    //   // After insertion 12 in binary tree
    //   //         10
    // //        /      \ 
    // //       11       9
    // //      /  \     / \
    // //     7   15   8  12

    root = deletion(root,9);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl<<maxDepth(root);

    return 0;
}