#include <iostream>
#include <algorithm> 
using namespace std;

class node {
public:
    int val;
    node *left;
    node *right;
    int height;

    node(int v) : val(v), left(nullptr), right(nullptr), height(1) {}
};

class avl {
private:
    node *root = nullptr;

    int getheight(node *n) {
        return n == nullptr ? 0 : n->height;
    }

    int getbalance(node *n) {
        return n == nullptr ? 0 : getheight(n->left) - getheight(n->right);
    }

    node* leftrotate(node *n) {
        node *t1 = n->right;
        node *t2 = t1->left;
        t1->left = n;
        n->right = t2;
        n->height = max(getheight(n->left), getheight(n->right)) + 1;
        t1->height = max(getheight(t1->left), getheight(t1->right)) + 1;
        return t1;
    }

    node* rightrotate(node *n) {
        node *t1 = n->left;
        node *t2 = t1->right;
        t1->right = n;
        n->left = t2;
        n->height = max(getheight(n->left), getheight(n->right)) + 1;
        t1->height = max(getheight(t1->left), getheight(t1->right)) + 1;
        return t1;
    }

    node* balance(node *root, int key) {
        int bal = getbalance(root);
        if (bal > 1 && key < root->left->val)
            return rightrotate(root);
        if (bal < -1 && key > root->right->val)
            return leftrotate(root);
        if (bal > 1 && key > root->left->val) {
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }
        if (bal < -1 && key < root->right->val) {
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }
        return root;
    }
    node* inserthelper(node* root, int key) {
        if (root == nullptr) {
            return new node(key);
        }
        if (key < root->val)
            root->left = inserthelper(root->left, key);
        else if (key > root->val)
            root->right = inserthelper(root->right, key);
        else
            return root;

        root->height = 1 + max(getheight(root->left), getheight(root->right));
        return balance(root, key);
    }

    node* findMin(node *n) {
        while (n->left != nullptr) {
            n = n->left;
        }
        return n;
    }

    node* removehelper(node *root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (key < root->val) {
            root->left = removehelper(root->left, key);
        } else if (key > root->val) {
            root->right = removehelper(root->right, key);
        } else { // Node found
            if (root->left == nullptr || root->right == nullptr) {
                node *temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }
            node *replace = findMin(root->right);
            root->val = replace->val;
            root->right = removehelper(root->right, replace->val);
        }

        root->height = 1 + max(getheight(root->left), getheight(root->right));
        return balance(root, key);
    }

public:
    void insert(int key) {
        root = inserthelper(root, key);
    }

    void remove(int key) {
        root = removehelper(root, key);
    }

    void inorder(node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    avl tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    cout << "Inorder traversal of the AVL tree is: ";
    tree.printInorder();
    tree.remove(50);
    cout << "After removing 50, inorder traversal is: ";
    tree.printInorder();

    return 0;
}
