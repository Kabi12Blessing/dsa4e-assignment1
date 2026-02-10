#include "interface.h"

/*
 File: implementation.cpp
 Description:
   Implements a stable merge sort for KeyEntry records.
   Sorting is done by keyValue in ascending order.
   Stability is preserved by preferring the left element
   when key values are equal.
*/

// Helper function to merge two sorted halves
static void merge(KeyEntry arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    KeyEntry L[n1];
    KeyEntry R[n2];

    // Copy data
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].keyValue < R[j].keyValue) {
            arr[k++] = L[i++];
        } else if (L[i].keyValue > R[j].keyValue) {
            arr[k++] = R[j++];
        } else {
            // Equal key values → take from left to preserve stability
            arr[k++] = L[i++];
        }
    }

    // Copy remaining elements
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Recursive merge sort
static void mergeSort(KeyEntry arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Public interface function
void stableMergeSort(KeyEntry arr[], int n) {
    if (n > 1) {
        mergeSort(arr, 0, n - 1);
    }
}
