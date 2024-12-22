
//merge sort  time complexity:"O(nlogn)" space comlexxity:"O(n)"
#include <iostream>
using namespace std;
void conquer(int arr[],int si,int mid,int ei){
    int merger[ei-si+1];
    int idx1=si;
    int idx2=mid+1;
    int x=0;
    while (idx1<=mid&&idx2<=ei)
    {
        if(arr[idx1]<=arr[idx2])
        {merger[x++]=arr[idx1++];}
        else{merger[x++]=arr[idx2++];}
    }
    while(idx1<=mid){
        merger[x++]=arr[idx1++];
    }
    while(idx2<=ei){
        merger[x++]=arr[idx2++];
    }
     for (int i = 0; i < x; i++) {
        arr[si + i] = merger[i];
    }
    
    }
void divide(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    divide(arr,si,mid);
    divide(arr,mid+1, ei);
    conquer(arr,si,mid,ei);
}
//bubble sort  time complexity:"O(n^2)" space comlexxity:"O(1)"
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

// selection sort  time complexity:"O(n^2)" space comlexxity:"O(1)"
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr, i, minIndex);
    }
}

//insertion sort   time complexity:"O(n^2)" space comlexxity:"O(1)"
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// shell sort  time complexity:"O(nlogn)  in leastcase O(n^2)" space comlexxity:"O(1)"
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


//quick sort time complexity:"O(nlogn)  in leastcase O(n^2)" space comlexxity:"O(n)"
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// First element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, low, i - 1);  // Place pivot in correct position
    return i - 1;
}
// Last element as pivot
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);  // Place pivot in correct position
    return i + 1;
}
 // Random index
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
