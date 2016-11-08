//
//  main.cpp
//  CS31 Project 4
//
//  Created by Austin Guo on 11/2/16.
//  Copyright © 2016 Austin Guo. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>

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

int main() {
    

    //final tests
    string h[7] = { "jill", "hillary", "donald", "tim", "", "evan", "gary" };
    assert(lookup(h, 7, "evan") == 5);
    assert(lookup(h, 7, "donald") == 2);
    assert(lookup(h, 2, "donald") == -1);
    assert(positionOfMax(h, 7) == 3);
    
    string g[4] = { "jill", "hillary", "gary", "mindy" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "jill?" && g[3] == "mindy?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "gary?" && g[3] == "hillary?");
    
    string e[4] = { "donald", "tim", "", "evan" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string d[5] = { "hillary", "hillary", "hillary", "tim", "tim" };
    assert(countRuns(d, 5) == 2);
    
    string f[3] = { "gary", "donald", "mike" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "mike" && f[2] == "gary");
    
    assert(separate(h, 7, "gary") == 3);
    
    cerr << "All Smallberg's tests succeeded" << endl;
    
    return 0;
}


/**
 *Append value to the end of each of the n elements of the array and return n. [Of course, in this and other functions, if n is negative, the paragraph above that starts "Notwithstanding" trumps this by requiring that the function return −1. Also, in the description of this function and the others, when we say "the array", we mean the n elements that the function is aware of.] For example:
 */
int appendToAll(string a[], int n, string value){
    if (n < 0) return -1;
    for (int i = 0; i < n; i++) {  //to append everything to each element in the array
        a[i] += value;
    }
    return n;
}

/**
 *Return the position of a string in the array that is equal to target; if there is more than one such string, return the smallest position number of such a matching string. Return −1 if there is no such string. As noted above, case matters: Do not consider "TIm" to be equal to "tIM". 
 */
int lookup(const string a[], int n, string target) {
    if (n < 0) return -1; //if the number of positions to check is negative
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {  // to check if any element in the array is the same as the target
            return i;
        }
    }
    return -1; //if target isn't in array or within first n elements
}

/**
*Return the position of a string in the array such that that string is >= every string in the array. If there is more than one such string, return the smallest position in the array of such a string. Return −1 if the array has no elements. For example:
 */
int positionOfMax(const string a[], int n) {
    if (n <= 0) return -1;
    int i = 0;
    int count = 0;
    string max = a[0];
    for (; i < n; i++) {
        if (a[i] > max) { //returning the first largest element to see the first max elements
            max = a[i];
            count = i;
        }
    }
    return count;
}

/**
 *Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array. Return the original position of the item that was moved to the end. Here's an example:
 */
int rotateLeft(string a[], int n, int pos) {
    if (n <= 0 || pos < 0) return -1;
    if (pos >= n) return -1;
    string temp = a[pos];
    int i = pos + 1;
    for (; i < n; i++) {  // shift all elements to the left from n onward
        a[i - 1] = a[i];
    }
    a[i - 1] = temp;
    return pos;
}

/**
 *Return the number of sequences of one or more consecutive identical items in a.
 */
int countRuns(const string a[], int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    int count = 0;
    int i = 0;
    string temp = a[0];
    while (i < n) {
        if (temp != a[i]) { // will check to see each new start of a run by going through the elements
            temp = a[i];
            count++;
        }
        i++;
    }
    count++; //accounting for the last sequence
    return count;
}


/**
 *Reverse the order of the elements of the array and return n. For example,
 */
int flip(string a[], int n){
    if (n < 0) return -1;
    for (int i = 0; i < n/2; i++) { //goes through and flips strings
        string temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
    return n;
}

/**
 *Return the position of the first corresponding elements of a1 and a2 that are not equal. n1 is the number of interesting elements in a1, and n2 is the number of interesting elements in a2. If the arrays are equal up to the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other. For example,
 */
int differ(const string a1[], int n1, const string a2[], int n2){
    if (n1 < 0 || n2 < 0) return -1; //return -1 if n1 or n2 = 0 because there's no element to compare, that's an out of bound error
    if (n1 == 0 || n2 == 0) return 0;
    int i = 0;
    while (i < n1 && i < n2) {
        //
        if (a1[i] != a2[i]) return i;
        i++;
    }
    if (n2 < n1) return n2;
    else return n1;
}

/**
 *If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning position in the array. Return −1 if a1 does not contain a2 as a contiguous subsequence. (Consider a sequence of 0 elements to be a subsequence of any sequence, even one with no elements, starting at position 0.) For example,
 */
int subsequence(const string a1[], int n1, const string a2[], int n2) {
    if (n2 == 0) return 0;
    if (n1 < 0 || n2 < 0 || n2 > n1) return -1; // no array can be a subsequence of an empty array
    int i = 0;
    int j = 0;
    int initial = -1;
    while (i < n1) {
        if (a1[i] == a2[j]) {
            initial = i;
            i++;
            j++;
            for (; i < n1; i++) {
                if (j >= n2) return initial; //if successfully compared all elements in second array
                if (a1[i] != a2[j]) {
                    j = 0; //have to compare elements again
                    initial = -1;
                    break;
                }
                j++;
            }
        }
        i++;
    }
    return initial;
}

/**
 *Return the smallest position in a1 of an element that is equal to any of the elements in a2. Return −1 if no element of a1 is equal to any element of a2. For example,
 */
int lookupAny(const string a1[], int n1, const string a2[], int n2) {
    if (n1 <= 0 || n2 <= 0) return -1;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (a1[i] == a2[j]) {
                return i;
            }
        }
    }
    return -1;
}

/**
 *Rearrange the elements of the array so that all the elements whose value is < separator come before all the other elements, and all the elements whose value is > separator come after all the other elements. Return the position of the first element that, after the rearrangement, is not < separator, or n if there are no such elements. For example,
 */
int separate(string a[], int n, string separator) {
    if (n < 0) return -1;
    for (int i = 0; i < n; i++) {
        string temp = a[i];
        for (int k = i; k < n; k++) {
            if (a[k] < temp) {
                a[i] = a[k];
                a[k] = temp;
                temp = a[i];
            }
        }
    }
    for (int j = 0; j < n; j++) {
        if (a[j] >= separator) {
            return j;
        }
    }
    return n;
}
