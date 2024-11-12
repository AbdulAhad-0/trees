#include <iostream>
using namespace std;

// Definition of the Node structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// BinaryTree class encapsulates all the operations related to the tree
class BinaryTree
{
private:
    Node *root; // Root of the binary tree

    // function to insert a new value recursively
    Node *insertHelper(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value); // Create a new node if current node is null
        }
        if (value < node->data)
        {
            node->left = insertHelper(node->left, value); // Insert in the left subtree
        }
        else
        {
            node->right = insertHelper(node->right, value); // Insert in the right subtree
        }
        return node;
    }

    // function for in-order traversal (left, root, right)

    void inorderTraversal(Node *node) const
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // function for pre-order traversal (root, left, right)
    void preorderTraversal(Node *node) const
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // function for post-order traversal (left, right, root)
    void postorderTraversal(Node *node) const
    {
        if (node == nullptr)
            return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    // function to delete a node from the binary tree
    Node *deleteNodeHelper(Node *node, int value)
    {
        if (node == nullptr)
            return node;

        if (value < node->data)
        {
            node->left = deleteNodeHelper(node->left, value); // Go to left subtree
        }
        else if (value > node->data)
        {
            node->right = deleteNodeHelper(node->right, value); // Go to right subtree
        }
        else
        {
            // Node found, now handle the cases
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: find the inorder successor (smallest in right subtree)
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNodeHelper(node->right, temp->data); // Delete the successor
        }
        return node;
    }

    // function to find the node with minimum value (used for deletion)
    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // function to delete the entire tree
    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "Deleting node with value: " << node->data << endl;
        delete node;
    }

    // function to print the tree in a simple 2D format
    void printTree(Node *node, int space) const
    {
        if (node == nullptr)
            return;

        space += 5;

        // Print right subtree first
        printTree(node->right, space);

        // Print current node after spacing
        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";
        cout << node->data << "\n";

        // Print left subtree
        printTree(node->left, space);
    }

public:
    // Constructor to initialize an empty tree
    BinaryTree() : root(nullptr) {}

    // Insert a new value into the binary tree
    void insert(int value)
    {
        root = insertHelper(root, value);
    }

    // Delete a node from the binary tree
    void deleteNode(int value)
    {
        root = deleteNodeHelper(root, value);
    }

    // Perform in-order traversal
    void inorderTraversal() const
    {
        inorderTraversal(root);
        cout << endl;
    }

    // Perform pre-order traversal
    void preorderTraversal() const
    {
        preorderTraversal(root);

        cout << endl;
    }

    // Perform post-order traversal
    void postorderTraversal() const
    {
        postorderTraversal(root);
        cout << endl;
    }

    // Print the tree structure
    void printTree() const
    {
        printTree(root, 0);
    }

    // Destructor to clean up the tree's memory
    ~BinaryTree()
    {
        deleteTree(root);
    }
};

int main()
{
    BinaryTree tree;

    // Insert nodes into the binary tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // Perform different traversals
    cout << "In-order traversal: ";
    tree.inorderTraversal();

    cout << "Pre-order traversal: ";
    tree.preorderTraversal();

    cout << "Post-order traversal: ";
    tree.postorderTraversal();

    // Print the binary tree structure
    cout << "\nBinary Tree Structure:\n";
    tree.printTree();

    // Delete a node
    cout << "\nDeleting node with value 10\n";
    tree.deleteNode(10);

    // Print the tree after deletion
    cout << "\nBinary Tree Structure After Deletion:\n";
    tree.printTree();

    return 0;
}