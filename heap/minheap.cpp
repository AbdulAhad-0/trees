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
        while(i > 0) {
            int p = (i - 1) / 2;
            if(arr[i] < arr[p]) {
                swap(arr[i], arr[p]);
                i = p;
            } else {
                return;
            }
        }
    }
    void del() {
        if(size <= 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    void buildheap() {
        for(int i = (size - 1) / 2; i >= 0; i--) {
            heapify(i);
        }
    }

    void heapSort() {
        buildheap();
        for(int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            size--;
            heapify(0);
        }
    }

    void print() {
        for(int i = 0; i < size; i++) {
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

    cout << "\nHeap array after insertion:" << endl;
    h.print();
    
    h.buildheap();
    cout << "\nHeap array after building min heap:" << endl;
    h.print();

    h.del();
    cout << "\nHeap array after deletion:" << endl;
    h.print();
    h.heapSort();
    cout << "\nArray after heap sort:" << endl;
    h.print();
    return 0;
}
