#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Merge function for strings
void merge(char arr[][], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    char L[n1][10], R[n2][10];

    for (i = 0; i < n1; i++)
        strcpy(L[i], arr[l + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], arr[m + 1 + j]);

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(char arr[][], int size) {
    for (int i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

int main() {
    char arr[][]; // assuming a maximum of 100 elements each with a max length of 9
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (characters or integers): ");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
