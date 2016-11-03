//
//  main.cpp
//  CS31 Project 4
//
//  Created by Austin Guo on 11/2/16.
//  Copyright © 2016 Austin Guo. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int separate(string a[], int n, string separator);

//helper method to test things
void printAll (string a[]){
    for (int i = 0; i < 7; i++) {
        cerr << a[i] << ", ";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string array[7] = {"Hi", "hi", "hello", "me", "my", "i", "I"}; //array to test methods
    printAll(array); //
    appendToAll(array, 5, "Smallberg");
    printAll(array); //
    return 0;
}


int appendToAll(string a[], int n, string value){
    if (n < 0) return -1;
    for (int i = 0; i < n; i++) {
        a[i] += value;
    }
    return n;
}

int lookup(const string a[], int n, string target) {
    if (n < 0) return -1; //if the number of positions to check is negative
    
    return n;
}

//int positionOfMax(const string a[], int n);
//int rotateLeft(string a[], int n, int pos);
//int countRuns(const string a[], int n);
//int flip(string a[], int n);
//int differ(const string a1[], int n1, const string a2[], int n2);
//int subsequence(const string a1[], int n1, const string a2[], int n2);
//int lookupAny(const string a1[], int n1, const string a2[], int n2);
//int separate(string a[], int n, string separator);
