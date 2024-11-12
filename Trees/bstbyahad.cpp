#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) : data(d), left(NULL), right(NULL) {}
};

class bst {
private:
    node* inserthelp(node* root, int d) {
        if (!root) {
            return new node(d);
        }
        if (d < root->data) {
            root->left = inserthelp(root->left, d);
        } else {
            root->right = inserthelp(root->right, d);
        }
        return root;
    }

    bool searchedtree(node* r, int d) {
        if (!r) {
            return false;
        }
        if (r->data == d) {
            return true;
        }
        return d < r->data ? searchedtree(r->left, d) : searchedtree(r->right, d);
    }

    int minvalue(node* n) {
        while (n->left != NULL) {
            n = n->left;
        }
        return n->data;
    }

    node* deletetree(node* root, int d) {
        if (!root) {
            return root;
        }
        if (d < root->data) {
            root->left = deletetree(root->left, d);
        } else if (d > root->data) {
            root->right = deletetree(root->right, d);
        } else {
            // Node with only one child or no child
            if (!root->left) {
                node* temp = root->right;
                delete root; // Free memory
                return temp;
            } else if (!root->right) {
                node* temp = root->left;
                delete root; // Free memory
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            root->data = minvalue(root->right);
            root->right = deletetree(root->right, root->data);
        }
        return root;
    }

public:
    node* root;
    
    bst() : root(NULL) {} // Constructor to initialize root

    void insert(int d) {
        root = inserthelp(root, d);
    }

    void inorder(node* n) {
        if (n) {
            inorder(n->left);
            cout << n->data << " ,";
            inorder(n->right);
        }
    }

    void postorder(node* n) {
        if (n) {
            postorder(n->left);
            postorder(n->right);
            cout << n->data << " ,";
        }
    }

    void preorder(node* n) {
        if (n) {
            cout << n->data << " ,";
            preorder(n->left);
            preorder(n->right);
        }
    }

    bool search(int d) {
        return searchedtree(root, d);
    }

    int findheight(node* r) {
        if (!r) return -1; // Return -1 for height of empty tree
        return 1 + max(findheight(r->left), findheight(r->right));
    }

    void deletet(int d) {
        root = deletetree(root, d);
    }

    // Public interface for traversals
    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
};

int main() {
    bst tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    
    cout << "Inorder: "; tree.inorder();
    cout << "Preorder: "; tree.preorder();
    cout << "Postorder: "; tree.postorder();
    
    cout << "Search for 4: " << (tree.search(4) ? "Found" : "Not Found") << endl;
    
    tree.deletet(3);
    cout << "Inorder after deleting 3: "; tree.inorder();

    return 0;
}
