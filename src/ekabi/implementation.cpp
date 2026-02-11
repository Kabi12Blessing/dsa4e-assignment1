#include "interface.h"

/*
 File: implementation.cpp

 Implements a stable merge sort for KeyEntry records.
 Sorting is done by keyValue in ascending order.
 Stability is guaranteed by preferring the left element
 when key values are equal.

 Time Complexity (Worst Case): O(n log n)
 Space Complexity: O(n)
*/


// Merge two sorted halves of arr[]
static void merge(KeyEntry arr[], int left, int mid, int right) {

    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Dynamically allocate temporary arrays 
    KeyEntry* leftArray = new KeyEntry[leftSize];
    KeyEntry* rightArray = new KeyEntry[rightSize];

    // Copy left half
    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = arr[left + i];
    }

    // Copy right half
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0;       // index for the leftArray
    int j = 0;       // index for e rightArray
    int k = left;    // index for e original array

    // Merge while both halves have elements
    while (i < leftSize && j < rightSize) {

        if (leftArray[i].keyValue < rightArray[j].keyValue) {
            arr[k++] = leftArray[i++];
        }
        else if (leftArray[i].keyValue > rightArray[j].keyValue) {
            arr[k++] = rightArray[j++];
        }
        else {
            // Equal values → take from left to preserve stability
            arr[k++] = leftArray[i++];
        }
    }

    // Copy any remaining elements from left half
    while (i < leftSize) {
        arr[k++] = leftArray[i++];
    }

    // Copy any remaining elements from right half
    while (j < rightSize) {
        arr[k++] = rightArray[j++];
    }

    // Free allocated memory
    delete[] leftArray;
    delete[] rightArray;
}


// Recursive merge sort
static void mergeSort(KeyEntry arr[], int left, int right) {

    if (left >= right) {
        return;   // Base case
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}


// Public function
void stableMergeSort(KeyEntry arr[], int n) {

    if (n <= 1) {
        return;
    }

    mergeSort(arr, 0, n - 1);
}
