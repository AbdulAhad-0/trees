#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    int height;
    
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
        height = 1; 
    }
};

class avl {
public:
    node* root;

    avl() {
        root = NULL;
    }
    
    node* rightrotate(node* y) {
        node* x = y->left;
        node* t2 = x->right;
        x->right = y;
        y->left = t2;
        y->height = max(getheight(y->left), getheight(y->right)) + 1;
        x->height = max(getheight(x->left), getheight(x->right)) + 1;
        return x;
    }
    int getheight(node* n) {
        return n ? n->height : 0;
    }
    node* leftrotate(node* x) {
        node* y = x->right;
        node* t2 = y->left;
        y->left = x;
        x->right = t2;
        x->height = max(getheight(x->left), getheight(x->right)) + 1;
        y->height = max(getheight(y->left), getheight(y->right)) + 1;
        return y;
    }

    int getbalance(node* n) {
        return n ? getheight(n->left) - getheight(n->right) : 0;
    }

    node* insert(node* n, int data) {
        if (n == NULL) {
            return new node(data);
        }
        if (data < n->data) {
            n->left = insert(n->left, data);
        } else if (data > n->data) {
            n->right = insert(n->right, data);
        } else {
            return n;
        }
        n->height = 1 + max(getheight(n->left), getheight(n->right));
        int bal = getbalance(n);
        if (bal > 1 && data < n->left->data) {
            return rightrotate(n);
        }
        if (bal<-1&&data>n->right->data) {return leftrotate(n);}
        if (bal> 1 && data > n->left->data) {
            n->left = leftrotate(n->left);
            return rightrotate(n);
        }
        if (bal<-1&&data<n->right->data) {
            n->right=rightrotate(n->right);
            return leftrotate(n);
        }
        return n;
    }
    void insert(int data) {
        root = insert(root, data);
    }
    void preorder(node* n) {
        if (n != NULL) {
            cout << n->data << " ";
            preorder(n->left);
            preorder(n->right);
        }
    }
    void leftrotateroot() {
        if (root) {
            root = leftrotate(root);
        }
    }
};
int main() {
    avl t;
    int initialvalues[] = {50, 30, 70, 20, 40, 60, 80};
    for (int value : initialvalues) {
        t.insert(value);
    }
    t.insert(55);
    t.leftrotateroot();
    cout << "preorder traversal after left rotation on the root: ";
    t.preorder(t.root);
    cout << endl;
    return 0;
}
