#include <iostream>
using namespace std;

class heap {
    int arr[100], size;

    void heapify(int i) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (left < size && arr[left] > arr[largest]) largest = left;
        if (right < size && arr[right] > arr[largest]) largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void buildheap() {
        for (int par = (size - 1) / 2; par >= 0; par--) heapify(par);
    }

public:
    heap() { size = 0; }

    void insert(int d) {
        arr[size] = d;
        size++;
        int i = size - 1;
        while (i > 0) {
            int par = (i - 1) / 2;
            if (arr[i] > arr[par]) {
                swap(arr[i], arr[par]);
                i = par;
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

    void deleteValue(int value) {
        int index = -1;
        for (int i = 0; i < size; i++) if (arr[i] == value) { index = i; break; }
        if (index == -1) return;
        arr[index] = arr[size - 1];
        size--;
        heapify(index);
    }

    void print() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void buildHeapFromArray(int input[], int n) {
        size = n;
        for (int i = 0; i < n; i++) arr[i] = input[i];
        buildheap();
    }

    void heapSort() {
        buildheap();
        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            size--;
            heapify(0);
        }
    }
    int kthsmallest(int k){
        heapSort();
        return arr[k-1];

    }
};

int main() {
    heap h;
    int input[] = {25, 30, 35, 11, 15, 19, 18, 55, 78, 36};
    int n = 10;
    h.buildHeapFromArray(input, n);

    cout << "Max Heap: ";
    h.print();

    h.heapSort();

    cout << "Sorted Array: ";
    h.print();

    return 0;
}
