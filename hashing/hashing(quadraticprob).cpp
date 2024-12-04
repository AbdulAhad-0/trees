
#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;  // Pointer to the array (hash table)
    int size;    // Size of the hash table

public:
    // Constructor to initialize the hash table with a given size
    HashTable(int s) {
        size = s;
        table = new int[size];  // Allocate memory for the table
        for (int i = 0; i < size; ++i) {
            table[i] = -1;  // Initialize all positions with -1 indicating empty spots
        }
    }

    // Hash function to get index from the key
    int hash(int key) {
        return key % size;  // Simple hash function (modulo operation)
    }
    // Function to insert a key using quadratic probing
    void insert(int key) {
        int index = hash(key);  // Get the initial index

        // Try quadratic probing (i^2 steps away)
        for (int i = 0; i < size; ++i) {
            int newIndex = (index + i * i) % size;  // Quadratic probing formula
            if (table[newIndex] == -1) {             // If the slot is empty
                table[newIndex] = key;              // Insert the key
                cout << "Inserted " << key << " at index " << newIndex << endl;
                return;
            }
        }
        cout << "Hash Table is full. Cannot insert " << key << endl; // If table is full
    }

    // Function to search for a key in the hash table
    bool search(int key) {
        int index = hash(key);  // Get the initial index

        // Try quadratic probing (i^2 steps away)
        for (int i = 0; i < size; ++i) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == -1) {
                return false; // Key not found, empty spot
            }
            if (table[newIndex] == key) {
                return true;  // Key found
            }
        }
        return false; // Key not found after full probing
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < size; ++i) {
            if (table[i] == -1)
                cout << "Index " << i << ": Empty\n";
            else
                cout << "Index " << i << ": " << table[i] << endl;
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~HashTable() {
        delete[] table;  // Deallocate the table array
    }
};

int main() {
    // Create a hash table of size 7
    HashTable ht(7);

    // Insert some values
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    ht.insert(60);

    // Display the table
    ht.display();

    // Search for an element
    int key = 30;
    if (ht.search(key)) {
        cout << "Key " << key << " found in the hash table." << endl;
    } else {
        cout << "Key " << key << " not found in the hash table." << endl;
    }

    return 0;
}