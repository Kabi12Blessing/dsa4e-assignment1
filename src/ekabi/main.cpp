#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include "interface.h"

using namespace std;
/*
Author: Eileen Blessing Kabi
Andrew ID: ekabi
Course: 04-630 Data Structures and Algorithms
Assignment 1

Description: This program reads crypto key entries from data/input.txt. Each entry contains a key indexand a hexadecimal key value.

The hexadecimal value is converted into an unsigned integer so that the keys can be compared numerically. All keys are stored in an array of records.
The array is then sorted in ascending order based on the numeric key value using a stable merge sort.The sorted results are written to data/output.txt.
The first line of the file contains my Andrew ID. Each following line contains the key index andthe original hexadecimal value.


Pseudo-code

Main Logic:
1. Open input and output files.
2. Read integer N.
3. Create an array to store N key records.
4. For each of the N entries:
     - Read key index and hexadecimal value.
     - Convert hexadecimal value to decimal.
     - Store all values in the array.
5. Sort the array in ascending order (using merge sort).
6. Write Andrew ID to the output file.
7. Write all sorted key entries.


Merge Sort Logic:

1. If the subarray has only one element, return.
2. Divide the array into two halves.
3. Recursively sort the left half.
4. Recursively sort the right half.
5. Merge the two sorted halves.
6. During merging:
     - Compare the numeric values.
     - If the values are equal,
       copy the element from the left half first.
       This preserves stability.


How Stability Is Ensured

Stability is handled during the merge step. When two key values are equal, the element from the left half is copied first. Since the left half 
contains elements that appeared earlier in the original input, their relative order is preserved.


Time Complexity 
n = totalKeys.
1. Reading Input
The loop: for (int i = 0; i < totalKeys; i++) runs n times. Each iteration performs constant-time work(reading values, converting hex, assigning fields).
Time = n × O(1) = O(n)


2. Sorting (mergeSort and merge) The function mergeSort divides the array into two halves each time it is called.

If the array size is n, the sizes become: n → n/2 → n/4 → ... → 1

The number of times the array can be divided is log₂(n). Therefore, recursion depth = log₂(n). At each recursion level, the merge function processes
every element in that level exactly once. Each element is copied into a temporary array and then copied back. 
So, at one recursion level, total work = n.

Since there are log₂(n) levels: Total sorting time = n × log₂(n)
Worst-case sorting time = O(n log n)

3. Writing Output

The loop that writes results runs n times.
Time = O(n)

Final Overall Time Complexity:

O(n) + O(n log n) + O(n)
= O(n log n)


Space Complexity

During each merge operation, two temporary arrays are created with sizes n1 and n2.
At the top level, n1 + n2 = n.
The maximum extra memory used at any moment is proportional to n.

Therefore, space complexity = O(n).



Testing

My program was tested with:

- N = 1 (minimum case)
- N = 1000 (maximum case)
- Reverse sorted input
- Already sorted input
- Multiple duplicate keys
- Boundary values such as 0x0000 and 0xFFFF, so cannot be below 1 or greater than 1000
- Different hexadecimal formats such as 0xA and 0x00A

All tests produced correct sorted output and maintained stability.
*/



int main() {

    ifstream inputFile("data/input.txt");
    ofstream outputFile("data/output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error: Could not open input or output file." << endl;
        return 1;
    }

    int totalKeys;

    // Read number of keys
    if (!(inputFile >> totalKeys)) {
        cout << "Error: Invalid number of keys." << endl;
        return 1;
    }

    // Check bounds
    if (totalKeys < 1 || totalKeys > 1000) {
        cout << "Error: N must be between 1 and 1000." << endl;
        return 1;
    }

    KeyEntry keys[1000];   // Maximum allowed size

    for (int i = 0; i < totalKeys; i++) {

        if (!(inputFile >> keys[i].keyIndex >> keys[i].hexKey)) {
            cout << "Error: Invalid input format at line " << i + 2 << endl;
            return 1;
        }

        unsigned int decimalValue;

        // Convertx hex string to decimal
        if (sscanf(keys[i].hexKey, "%x", &decimalValue) != 1) {
            cout << "Error: Invalid hexadecimal value at line " << i + 2 << endl;
            return 1;
        }

        keys[i].keyValue = decimalValue;
        keys[i].originalPosition = i;
    }

    // Perform stable merge sort
    stableMergeSort(keys, totalKeys);

    // Write output
    outputFile << "ekabi" << endl;

    for (int i = 0; i < totalKeys; i++) {
        outputFile << keys[i].keyIndex << " "
                   << keys[i].hexKey << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
