#ifndef INTERFACE_H
#define INTERFACE_H

/*
 Author: Eileen Blessing Kabi
 Andrew ID: ekabi

 File: interface.h
 Description:
   Interface definitions for the key analysis on 2-DES.
   Declares the data structure and the stable sorting function.
*/

// Represents one key record from input
struct KeyEntry {
    int keyIndex;                 // original key index from input
    unsigned int keyValue;        // decimal value of the hexadecimal key
    char hexKey[20];              // original hexadecimal string 
    int originalPosition;         // position in input (for stability)
};

// Sorts the array of KeyEntry by keyValue in ascending order.
// since the sort must be stable.
void stableMergeSort(KeyEntry arr[], int n);

#endif // INTERFACE_H
