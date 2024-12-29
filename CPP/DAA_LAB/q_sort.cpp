#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (arr[i] <= pivot && i <= high) {
            i++;
        }
        while (arr[j] > pivot && j >= low) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int n;
    clock_t s,e;
    double t;
    cout << fixed << setprecision(6);
    cout << "\nEnter number of elements in the array : ";
    cin >> n;
    srand(time(0));
    int arr1[1000], arr2[1000];

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 100;
    }
    cout << "\nOriginal array : ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << "\t";
    }
    s = clock();
    quickSort(arr1, 0, n - 1);
    e= clock();
    cout << "\n\n Sorted array : ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << "\t";
    }
    t = (double)(e - s) / CLOCKS_PER_SEC;
    cout << "\n\nTime taken for Quick Sort with pivot at 1st position is " << t<< "seconds\n\n";
   
    for (int i = 0; i < n; i++) {
        arr2[i] = rand() % 2;
    }
    cout << "\nOriginal array : ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << "\t";
    }
    s = clock();
    quickSort(arr2, 0, n - 1);
    e = clock();
    cout << "\n\n Sorted array : ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << "\t";
    }
    t = (double)(e - s) / CLOCKS_PER_SEC;
    cout << "\n\nTime taken for Quick Sort of binary numbers with pivot at 1st position is " << t << "seconds\n\n";
    return 0;
}