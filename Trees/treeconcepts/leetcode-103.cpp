#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int val;
    node*right;
    node*left;
    node(int v):val(v),right(nullptr),left(nullptr){}
};
class bst{
    void solve(node*root,vector<vector<int>>& a,int l,bool iseven){
        if(!root) return;
        if(a.size()<=l){
            a.push_back(vector<int>());
        }
        if(iseven){
            a[l].push_back(root->val);
        }else{
            a[l].insert(a[l].begin(),root->val);
        }
        solve(root->left,a,l+1,!iseven);
        solve(root->right,a,l+1,!iseven);
    }
    public:
   node* root;

    bst() : root(nullptr) {}

    void insert(int value) {
        root = insertHelper(root, value);
    }

    node* insertHelper(node* root, int value) {
        if (!root) return new node(value);
        if (value < root->val) {
            root->left = insertHelper(root->left, value);
        } else {
            root->right = insertHelper(root->right, value);
        }
        return root;
    }

    // Method for zigzag level order traversal
    void zigzagTraversal() {
        vector<vector<int>> a1;
        solve(root, a1, 0, true); 
        for (const auto& level : a1) {
            for (int val : level) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    bst tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    tree.zigzagTraversal();  // Perform zigzag traversal
}
