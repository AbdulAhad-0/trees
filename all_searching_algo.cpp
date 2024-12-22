#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Binary Search Function
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Target not found
}

// Interpolation Search Function
int interpolationSearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        // Estimate the position
        int pos = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos] == target) {
            return pos; // Target found
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> data = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target;

    cout << "Enter the target to search: ";
    cin >> target;

    // Perform Binary Search
    int binaryResult = binarySearch(data, target);
    if (binaryResult != -1) {
        cout << "Binary Search: Target found at index " << binaryResult << "\n";
    } else {
        cout << "Binary Search: Target not found.\n";
    }

    // Perform Interpolation Search
    int interpolationResult = interpolationSearch(data, target);
    if (interpolationResult != -1) {
        cout << "Interpolation Search: Target found at index " << interpolationResult << "\n";
    } else {
        cout << "Interpolation Search: Target not found.\n";
    }

    return 0;
}
