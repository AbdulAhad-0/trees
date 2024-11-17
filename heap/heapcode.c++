#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        size = 0;
    }

    void insert(int d) {
        arr[size] = d;
        int idx = size;
        size++;

        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (arr[parent] < arr[idx]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            } else {
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.display();
    return 0;
}
