#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* arr;
    int size;

    void heapify(int N, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < N && arr[l] > arr[largest])
            largest = l;
        if (r < N && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(N, largest);
        }
    }

public:
    MaxHeap(int* inputArr, int N) {
        arr = inputArr;
        size = N;
        buildHeap();
    }

    void buildHeap() {
        for (int i = (size / 2) - 1; i >= 0; i--)
            heapify(size, i);
    }

    void printHeap() const {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int N = sizeof(arr) / sizeof(arr[0]);

    MaxHeap heap(arr, N);
    heap.printHeap();

    return 0;
}
