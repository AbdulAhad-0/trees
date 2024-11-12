class TreeNode{
    public:
    int val;
    TreeNode*right;
    TreeNode*left;
    TreeNode(int v):val(v),right(nullptr),left(nullptr){}
};
class Solution {
    TreeNode* solve(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) {
            return solve(root->right, low, high);
        }
        if (root->val > high) {
            return solve(root->left, low, high);
        }
        root->left = solve(root->left, low, high);
        root->right = solve(root->right, low, high);
        return root;
    }

public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};
