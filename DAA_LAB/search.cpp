#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int linearSearchIterative(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int linearSearchRecursive(int arr[], int key, int index, int n) {
    if (index == n) {
        return -1;
    }
    if (arr[index] == key) {
        return index;
    }
    return linearSearchRecursive(arr, key, index + 1, n);
}

int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, high, key);
        } else {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }
    }
    return -1;
}

int main() {
    srand(time(0)); // Seed for random number generation
    int n, key;
    clock_t start, end;
    double cpu_time_used;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];

    // Generate a random array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Assuming elements are in these range 0-99
    }
    sort(arr, arr + n); // Sort the array for binary search
    cout <<"the array \n";
    for(int i=0; i<n; i++){
        cout<<arr[i] << " ";
    }

    cout << "\n Enter the element to search: ";
    cin >> key;

    // Linear Search Iterative
    start = clock();
    int resultLinearIterative = linearSearchIterative(arr, n, key);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "Linear Search (Iterative): ";
    if (resultLinearIterative != -1) {
        cout << "Element found at index: " << resultLinearIterative << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    cout << "Time taken for Linear Search (Iterative): " << cpu_time_used << " seconds\n";

    // Linear Search Recursive
    start = clock();
    int resultLinearRecursive = linearSearchRecursive(arr, key, 0, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "Linear Search (Recursive): ";
    if (resultLinearRecursive != -1) {
        cout << "Element found at index: " << resultLinearRecursive << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    cout << "Time taken for Linear Search (Recursive): " << cpu_time_used << " seconds\n";

    // Binary Search Iterative
    start = clock();
    int resultBinaryIterative = binarySearchIterative(arr, n, key);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "Binary Search (Iterative): ";
    if (resultBinaryIterative != -1) {
        cout << "Element found at index: " << resultBinaryIterative << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    cout << "Time taken for Binary Search (Iterative): " << cpu_time_used << " seconds\n";

    // Binary Search Recursive
    start = clock();
    int resultBinaryRecursive = binarySearchRecursive(arr, 0, n - 1, key);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "Binary Search (Recursive): ";
    if (resultBinaryRecursive != -1) {
        cout << "Element found at index: " << resultBinaryRecursive << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    cout << "Time taken for Binary Search (Recursive): " << cpu_time_used << " seconds\n";

    return 0;
}