#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        size = 0;
    }

    void insert(int d) {
        arr[size] = d;
        size++;
        int i = size - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (arr[i] > arr[p]) { // Max-Heap logic
                swap(arr[i], arr[p]);
                i = p;
            } else {
                return;
            }
        }
    }

    void del() {
        if (size <= 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    void heapify(int i) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;
        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(largest);
        }
    }

    void buildheap() {
        for (int i = (size - 1) / 2; i >= 0; i--) {
            heapify(i);
        }
    }

    void heapsort() {
        int j = size;
        buildheap();
        for (int i = j - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            j--;
            size--;  // Temporarily decrease size for heapify
            heapify(0);
        }
        size = j;  // Restore original size
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    cout << "\nBasic array:" << endl;
    h.print();

    h.buildheap();
    cout << "Heap array:" << endl;
    h.print();

    cout << "Heap array after deletion:" << endl;
    h.del();
    h.print();

    cout << "Heap sorted:" << endl;
    h.heapsort();
    h.print();

    return 0;
}
