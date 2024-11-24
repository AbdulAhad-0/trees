#include<iostream>
#include <string>
#include<cmath>
#include<vector>
using namespace std;
class table{
    public:
    int id;
    string name;
    int age;
    table():id(),name(),age(){}
    table(int d,string n,int a):id(d),name(n),age(a){}
    
};
class node {
public:
    table student;
    node* left;
    node* right;
    int height;
    
     node(table d) : student(d), left(NULL), right(NULL), height(1) {}
};
class avl{
    node*rotateright(node* n){
    node*x= n->left;
    node* t2=x->right;
    x->right=n;
    n->left=t2;
    x->height=max(getheight(root->left),getheight(root->right))+1;
    n->height=max(getheight(root->left),getheight(root->right))+1;
    return x;
}
node*rotateleft(node *n){
    node*x=n->right;
    node*y=x->left;
    x->left=n;
    n->right=y;
}
node* minval(node* n) {
        node* current = n;
        while (current->left != NULL)
            current = current->left;
        return current;
    }
    node* inserthelper(node*root,node*  n){
        if(!root){
            root=n;
            return root;
        }
        if(root->student.id>n->student.id){
            root->right=inserthelper(root->right,n);
        }
        else if(root->student.id<n->student.id){
            root->left=inserthelper(root->left,n);
        }
        else{
            return root;
        }
        root->height=max(getheight(root->left), getheight(root->right))+1;
        int  b=getbalance(root);
        if(b>1&&n->student.id<root->left->student.id)
            return rotateright(root);
        if(b<-1&&n->student.id>root->right->student.id)
            return rotateleft(root);
        if(b>1&&n->student.id>root->left->student.id){
            root->left=rotateleft(root);
            return rotateright(root);}
        if(b<-1&&n->student.id<root->left->student.id){
            root->right=rotateright(root);
            return rotateleft(root);}
    }
    int getheight(node* node){
        if(node == NULL){
            return 0;
        }
        return node->height;
    }
    int getbalance(node*n){
        return (getheight(root->left)-getheight(root->right));
    }
    node* searchhelper(node* root, int id) {
    if (!root||root->student.id==id) {
            return root;
        }
    if (id<root->student.id) {
           return searchhelper(root->left,id);
        }
        return searchhelper(root->right,id);
    }
    node* deletehelper(node* root, int id) {
    if (!root)
        return root;

    if (id < root->student.id)
        root->left = deletehelper(root->left, id);
    else if (id > root->student.id)
        root->right = deletehelper(root->right, id);
    else {
    if ((root->left == NULL) || (root->right == NULL)) {
    node* temp = root->left ? root->left : root->right;
    if (!temp) {
        temp = root;
        root = NULL;
    } else
        *root = *temp;
    delete temp;
    } else {
    node* temp = minval(root->right);
    root->student = temp->student;
    root->right = deletehelper(root->right, temp->student.id);
    }
}
    if (!root)
        return root;

    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    int balance = getbalance(root);
    if (balance > 1 && getbalance(root->left) >= 0)
        return rotateright(root);
    if (balance > 1 && getbalance(root->left) < 0) {
        root->left = rotateleft(root->left);
        return rotateright(root);}
    if (balance < -1 && getbalance(root->right) <= 0)
        return rotateleft(root);
    if (balance < -1 && getbalance(root->right) > 0) {
        root->right = rotateright(root->right);
        return rotateleft(root);}
    return root;
}
 void inorder(node* n) {
        if (n) {
            inorder(n->left);
            cout << "id: "<<n->student.id << " ,"<<"name: "<<n->student.name << " ,"<<"age: "<<n->student.age << endl;
            inorder(n->right);
        }
    }
    
    void postorder(node* n) {
        if (n) {
            postorder(n->left);
            postorder(n->right);
            cout << "id: "<<n->student.id << " ,"<<"name: "<<n->student.name << " ,"<<"age: "<<n->student.age << endl;
        }
    }
    void preorder(node* n) {
        if (n) {
            cout << "id: "<<n->student.id << " ,"<<"name: "<<n->student.name << " ,"<<"age: "<<n->student.age << endl;
            preorder(n->left);
            preorder(n->right);
        }
    }
    
    public:
    node* root;
    avl():root(NULL){}
    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    
    void insert(table d){
        node* n=new node(d);
        root=inserthelper(root,n);
    }
     node* search(int id) {
        return searchhelper(root, id);
    }
    void deleteNode(int id) {
        root=deletehelper(root, id);
    }
};
class bst {
private:
    node* inserthelp(node* root, table d) {
    if (!root) {
        return new node(d);
    }
    if (d.id< root->student.id) {
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
    if (r->student.id == d) {
        return true;
    }
    return d < r->student.id ? searchedtree(r->left, d) : searchedtree(r->right, d);
    }

    int minvalue(node* n) {
        while (n->left != NULL) {
            n = n->left;
        }
        return n->student.id;
    }

    node* deletetree(node* root, int d) {
        if (!root) {
            return root;
        }
        if (d < root->student.id) {
            root->left = deletetree(root->left, d);
        } else if (d > root->student.id) {
            root->right = deletetree(root->right, d);
        } else {
            if (!root->left) {
                node* temp = root->right;
                delete root; 
                return temp;
            } else if (!root->right) {
                node* temp = root->left;
                delete root; 
                return temp;
            }
            root->student.id = minvalue(root->right);
            root->right = deletetree(root->right, root->student.id);
        }
        return root;
    }

public:
    node* root;
    
    bst() : root(NULL) {} 
    void insert(table d) {
        root = inserthelp(root, d);
    }

    void inorder(node* n) {
        if (n) {
            inorder(n->left);
            cout << "id: "<<n->student.id << " ,"<<"name: "<<n->student.name << " ,"<<"age: "<<n->student.age << endl;
            inorder(n->right);}}
    void postorder(node* n) {
        if (n) {
            postorder(n->left);
            postorder(n->right);
            cout << "id: "<<n->student.id << " ,"<<"name: "<<n->student.name << " ,"<<"age: "<<n->student.age << endl;}
}
    void preorder(node* n) {
        if (n) {
            cout << "id: "<<n->student.id << " ,"<<"name: "<<n->student.name << " ,"<<"age: "<<n->student.age << endl;
            preorder(n->left);
            preorder(n->right);}}

    bool search(int d) {return searchedtree(root, d);}
    int findheight(node* r) {
        if (!r) return -1; 
        return 1 + max(findheight(r->left), findheight(r->right));
    }
    void deletet(int d) {
        root = deletetree(root, d);}
    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
};
class bnode {
    vector<table> keys;
    vector<bnode*> children;
    bool leaf;
    int t;
    void split(int i, bnode *y) {
        bnode *z = new bnode(y->t, y->leaf);
        z->keys.assign(y->keys.begin() + t, y->keys.end());
        y->keys.resize(t - 1);
        if (!y->leaf) {
            z->children.assign(y->children.begin() + t, y->children.end());
            y->children.resize(t);
        }
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    }
    void insertnonfull(const table &k) {
        int i = keys.size() - 1;
        if (leaf) {
            while (i >= 0 && keys[i].id > k.id) i--;
            keys.insert(keys.begin() + i + 1, k);
        } else {
            while (i >= 0 && keys[i].id > k.id) i--;
            i++;
            if (children[i]->keys.size() == 2 * t - 1) {
                split(i, children[i]);
                if (keys[i].id < k.id) i++;
            }
            children[i]->insertnonfull(k);
        }
    }

public:
    bnode(int t, bool leaf) : t(t), leaf(leaf) {}

    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!leaf) children[i]->traverse();
            cout << keys[i].id << " " << keys[i].name << " " << keys[i].age << endl;
        }
        if (!leaf) children[i]->traverse();
    }

    bnode* search(int id) {
        int i = 0;
        while (i < keys.size() && id > keys[i].id) i++;
        if (i < keys.size() && keys[i].id == id) return this;
        if (leaf) return nullptr;
        return children[i]->search(id);
    }
    friend class b_tree;
};
class b_tree {
    bnode *root;
    int t;
public:
    b_tree(int t) : root(nullptr), t(t) {}
    void traverse() {
        if (root) root->traverse();
    }
    bnode* search(int id) {
        return root ? root->search(id) : nullptr;
    }
    void insert(const table &k) {
        if (!root) {
            root = new bnode(t, true);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == 2 * t - 1) {
                bnode *s = new bnode(t, false);
                s->children.push_back(root);
                s->split(0, root);
                root = s;
                root->insertnonfull(k);
            } else {
                root->insertnonfull(k);
            }
        }
    }
};
int main() {
    table s1(1, "Alice", 20);
    table s2(2, "Bob", 21);
    table s3(3, "Charlie", 22);
    table s4(4, "David", 23);
    table s5(5, "Eva", 24);
    avl at;
    bst bt;
    b_tree b_tree(3); 

    int c, id;
    table s;
    bool found;
    bnode* result = nullptr;
    cout<<" Roll no : 23k-0883"<<endl;
    cout<<endl<<endl<<endl;
    while (true) {
        cout << "1. Insert into AVL Tree"<<endl;
        cout << "2. Insert into BST"<<endl;
        cout << "3. Insert into B-Tree"<<endl;
        cout << "4. Search in AVL Tree"<<endl;
        cout << "5. Search in BST"<<endl;
        cout << "6. Search in B-Tree"<<endl;
        cout << "7. Delete from AVL Tree"<<endl;
        cout << "8. Delete from BST"<<endl;
        cout << "9. Delete from B-Tree"<<endl;
        cout << "10. Inorder traversal of AVL Tree"<<endl;
        cout << "11. Inorder traversal of BST"<<endl;
        cout << "12. Inorder traversal of B-Tree "<<endl;
        cout << "13. Exit"<<endl;
        cout << "Choose any no: "<<endl;
        cin >> c;
    switch (c) {
    case 1: 
    cout << "Enter student id, name and age: ";
    cin >> s.id >> s.name >> s.age;
    at.insert(s);
    break;
    case 2:
    cout << "Enter student id, name and age: ";
    cin >> s.id >> s.name >> s.age;
    bt.insert(s);
    break;
    case 3:
    cout << "Enter student id, name and age: ";
    cin >> s.id >> s.name >> s.age;
    b_tree.insert(s);
    break;
    case 4:
    cout << "Enter student id to search: ";
    cin >> id;
    if (at.search(id)) {
        cout << "Student found in AVL Tree\n";
    } else {
        cout << "Student not found in AVL Tree\n";
    }
    break;
    case 5:
    cout << "Enter student id to search: ";
    cin >> id;
    found = bt.search(id);
    if (found) {
        cout << "Student found in BST\n";
    } else {
        cout << "Student not found in BST\n";
    }
    break;
    case 6:
    cout << "Enter student id to search: ";
    cin >> id;
    result = b_tree.search(id);
    if (result) {
        cout << "Student found in B-Tree\n";
    } else {
        cout << "Student not found in B-Tree\n";
    }
    break;
    case 7:
    cout << "Enter student id to delete: ";
    cin >> id;
    at.deleteNode(id);
    break;
    case 8:
    cout << "Enter student id to delete: ";
    cin >> id;
    bt.deletet(id);
    break;
    case 9:
    cout << "Enter student id to delete: ";
    cin >> id;
    cout << "Deletion functionality is not implemented in B-Tree.\n";
    break;
    case 10:
    cout << "Inorder traversal of AVL Tree:\n";
    at.inorder();
    break;
    case 11:
    cout << "Inorder traversal of BST:\n";
    bt.inorder();
    break;
    case 12:
    cout << "Inorder traversal of B-Tree:\n";
    b_tree.traverse();
    break;
    case 13:
    cout << "Exiting the program.\n";
    return 0;
    default:
        cout << "Invalid c. Please try again.\n";
}
}
    return 0;
}