#include <iostream>
#include <vector>
#include <string>
using namespace std;

class dataitem {
public:
    string data;
    int key;
    dataitem* next;

    dataitem(int k, string d) : key(k), data(d), next(nullptr) {}
};
class sll { 
public:
    dataitem* root;
    sll() : root(nullptr) {}

    void insert(int key, string data) {
        dataitem* newItem = new dataitem(key, data);
        newItem->next = root;
        root = newItem;
    }

    dataitem* search(int key) {
        dataitem* current = root;
        while (current) {
            if (current->key == key)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void remove(int key) {
        dataitem* current = root;
        dataitem* prev = nullptr;

        while (current && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (!current) // Key not found
            return;

        if (!prev) // Removing the root
            root = current->next;
        else
            prev->next = current->next;

        delete current;
    }

    void display() {
        dataitem* current = root;
        while (current) {
            cout << "(" << current->key << ", " << current->data << ") -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }
};
class hashtable {
public:
    vector<sll*> hasharray;
    int size;
    hashtable(int s) : size(s) {
        hasharray.resize(size, nullptr);
        for (int i = 0; i < size; i++) {
            hasharray[i] = new sll();
        }
    }
    int hashFunction(int key) {
        return key % size;
    }
    void insert(int key, string data) {
        int hashIndex = hashFunction(key);
        hasharray[hashIndex]->insert(key, data);
    }
    string search(int key) {
        int hashIndex = hashFunction(key);
        dataitem* item = hasharray[hashIndex]->search(key);
        return item ? item->data : "Not found";
    }
    void remove(int key) {
        int hashIndex = hashFunction(key);
        hasharray[hashIndex]->remove(key);
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            hasharray[i]->display();
        }
    }
};
int main() {
    hashtable ht(5);
    ht.insert(1, "Data1");
    ht.insert(6, "Data6");
    ht.insert(11, "Data11");
    cout << "Hash Table Contents:\n";
    ht.display();
    cout << "Search for key 6: " << ht.search(6) << endl;
    cout << "Removing key 6.\n";
    ht.remove(6);
    ht.display();
    return 0;
}
