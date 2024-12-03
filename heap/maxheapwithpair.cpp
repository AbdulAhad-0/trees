#include <iostream>
using namespace std;

class heap {
public:
    struct Pair {
        int first;
        int second;
    };

    Pair arr[100];
    int size;

    heap() {
        size = 0;
    }

    void insert(int a, int b) {
        arr[size].first = a;
        arr[size].second = b;
        size++;
        int i = size - 1;
        while(i > 0) {
            int p = (i - 1) / 2;
            if(arr[i].first + arr[i].second > arr[p].first + arr[p].second) {
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
        int largest = i;

        if (left < size && (arr[left].first + arr[left].second) > (arr[largest].first + arr[largest].second)) {
            largest = left;
        }
        if (right < size && (arr[right].first + arr[right].second) > (arr[largest].first + arr[largest].second)) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
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
            cout << "(" << arr[i].first << ", " << arr[i].second << ") ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(50, 10);
    h.insert(55, 5);
    h.insert(53, 7);
    h.insert(52, 9);
    h.insert(54, 6);

    cout << "\nHeap array after insertion:" << endl;
    h.print();

    h.buildheap();
    cout << "\nHeap array after building max heap based on sum:" << endl;
    h.print();

    h.del();
    cout << "\nHeap array after deletion:" << endl;
    h.print();

    h.heapSort();
    cout << "\nArray after heap sort:" << endl;
    h.print();

    return 0;
}
