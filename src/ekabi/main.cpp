#include <iostream>
#include <fstream>
#include <cstring>
#include "interface.h"

/*
 Author: Eileen Blessing Kabi
 Andrew ID: ekabi

 File: main.cpp
 Description:
   Reads cryptographic key data from data/input.txt,
   sorts the keys using a stable merge sort,
   and writes the sorted output to data/output.txt.
*/

int main() {
    std::ifstream inFile("data/input.txt");
    std::ofstream outFile("data/output.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening input or output file." << std::endl;
        return 1;
    }

    int N;
    inFile >> N;

    KeyEntry keys[N];

    for (int i = 0; i < N; i++) {
        inFile >> keys[i].keyIndex >> keys[i].hexKey;

        // Convert hex string to decimal value
        sscanf(keys[i].hexKey, "%x", &keys[i].keyValue);

        // Track original position for stability
        keys[i].originalPosition = i;
    }

    // Sort keys by keyValue (stable)
    stableMergeSort(keys, N);

    // Output results
    outFile << "ekabi" << std::endl;   // Andrew ID on first line

    for (int i = 0; i < N; i++) {
        outFile << keys[i].keyIndex << " "
                << keys[i].hexKey << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
