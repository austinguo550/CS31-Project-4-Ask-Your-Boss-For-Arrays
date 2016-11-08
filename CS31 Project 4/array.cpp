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
    
    cout << "All Smallberg's tests succeeded" << endl;
    
    //my tests
    
    //first tests
    //Tests for appendToAll function
    
    string chips[] = {"lays", "doritos", "fritos", "tortilla", "", "bbq"};
    
    string answer[] = {"lays chips", "doritos chips", "fritos chips", "tortilla chips", " chips", "bbq chips"};
    
    
    
    
    
    assert(appendToAll(chips, 6, " chips") == 6 );
    
    for(int i = 0; i < 6; i++){
        
        assert(chips[i] == answer[i]); //functionality check to see if string appended to original
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    //Tests for lookup function
    
    string countries[] = {"india", "china", "mexico", "turkey", "japan", "turkey"};
    
    assert(lookup(countries, 5, "italy") == -1); //return -1 if country not found
    
    assert(lookup(countries, -1, "india") == -1); //return -1 because illegal array size
    
    assert(lookup(countries, 3, "japan") == -1); //return -1. country not found in first three
    
    assert(lookup(countries, 5, "turkEy") == -1); //return -1 because case-sensitive
    
    assert(lookup(countries, 0, "china") == -1); //return 0 because no elements to look at
    
    assert(lookup(countries, 5, "mexico") == 2); //return 2 because mexico in position 2
    
    assert(lookup(countries, 5, "turkey") == 3); //return 3 because turkey first in position 3
    
    
    //Tests for positionOfMax function
    
    string animals[] = {"fox", "lion", "dog", "rat", "snake", "money", "moose", "wolves"};
    
    assert(positionOfMax(animals, 8) == 7); //return 7 because wolves is last element
    
    assert(positionOfMax(animals, -3) == -1); //return -1 because illegal array size
    
    assert(positionOfMax(animals, 3) == 1); //return 1. animal found in first three is lion
    
    assert(positionOfMax(animals, 0) == -1); //return -1 because parameter is 0
    
    assert(positionOfMax(animals, 5) == 4); //return 4 because animal found in first
    
    
    
    string names[] = {"jon", "kanye", "sean", "trav"};
    
    
    
    assert(positionOfMax(names, 1) == 0); //return 0 because only 1 element to look at
    
    assert(positionOfMax(names, 3) == 2); //return 2. check to see if array is bounded
    
    

    
    //Tests for rotateLeft function
    
    string brands[] = {"nike", "dolce", "gucci", "louis", "prada"};
    
    string brandsRotateDolce[] = {"nike", "gucci", "louis", "prada", "dolce"};
    

    assert(rotateLeft(brands, 5, 4) == 4); //functionality check. returns pos placement.
    
    assert(rotateLeft(brands, -3, 5) == -1); //check for invalid array size
    
    assert(rotateLeft(brands, 3, -2) == -1); //check for invalid pos
    
    assert(rotateLeft(brands, 0, 2) == -1); //return -1 because array size is 0. pos must be 0
    
    assert(rotateLeft(brands, 3, 2) == 2); //check for bound. return pos functionality check
    
    //output new array to check if function worked
    assert(rotateLeft(brands, 5, 1) == 1);
    
    //output array should be {nike, gucci, louis, prada, dolce}
    
    for(int i = 0; i<5; i++){
        
        assert(brands[i] == brandsRotateDolce[i]);
        
    }

    
    //Tests for countRuns function
    
    string rappers[] = {"kanye", "jay", "trav", "asap", "sean", "kdot"};
    
    assert(countRuns(rappers, 6) == 6); //normal check to check functionality
    
    assert(countRuns(rappers, -3) == -1); //return -1 because illegal array size
    
    assert(countRuns(rappers, 0) == 0); //return 0 because parameter is 0
    
    
    
    string rappersDup[] = {"kanye", "jay", "kanye", "asap", "kanye", "kdot"};
    
    
    
    assert(countRuns(rappersDup, 6) == 6); //return 4. 4 unique items in list
    
    assert(countRuns(rappersDup, 3) == 3); //return 2 because bounded to first 3 elements
    
    assert(countRuns(rappers, 1) == 1); //return 1 because only 1 unique element to look at
    
    
    
    string rappersBound[] = {"kanye", "jay", "trav", "jay", "sean", "kdot"};
    
    assert(countRuns(rappersBound, 4) == 4); //return 3. check for bound and unique elements
    
    
    
    string dasTest[] = {
        
        "tim", "ajamu", "mike", "mike", "donald", "donald", "donald", "mike", "mike"
        
    };
    
    
    
    assert(countRuns(dasTest, 9) == 5);
    
    //Tests for flip function
    
    string friends[] = {"syd", "ian", "costa", "nigel", "ally", "trav", "scott"};
    
    assert(flip(friends, 5) == 5); //return 5 because return value 5. check for bound
    
    assert(flip(friends, -1) == -1); //return -1 because illegal array size
    
    assert(flip(friends,0) == 0); //return 0. friends flipped.
    
    assert(flip(friends,7) ==7); //check normal array for functionality

    
    
    string friendsBlank[] = {"syd", "ian", "", "nigel", "ally", "trav"};
    
    assert(flip(friendsBlank, 6) == 6); //check for return 6 even though there is a blank.
    
    

    
    
    //Tests for differ function
    
    string country[] = {"india", "china", "mexico", "turkey", "japan", "turkey"};
    
    string people[] = {"musk", "bell", "tesla", "stark"};
    
    
    
    assert(differ(country, 6, people, 4) == 0); //return 0 because differ at 0
    
    assert(differ(country, -4, people, 4) == -1); //return -1 because illegal array size
    
    assert(differ(country, 6, people, -5) == -1); //return -1 because illegal array size
    
    assert(differ(country, 3, people, 4) == 0); //return 0 because differ at 0
    
    
    
    
    
    string job[] = {"business", "inventor", "scientist", "hero", "music", "rapper"};
    
    string random[] = {"business", "inventor", "tesla", "stark", "legend", "carter"};
    
    
    
    assert(differ(job, 6, random, 6) == 2); //return 2 because differ at 2
    
    
    
    
    
    
    
    string a[] = {"business", "inventor", "scientist", "hero", "music", "rapper"};
    
    string b[] = {"business", "inventor", "scientist", "hero", "music", "rapper"};
    
    
    
    
    
    assert(differ(a, 6, b, 6) == 6); //return 6 because end of arrays, all same
    
    
    
    
    
    string c[] = {"business", "inventor", "scientist", "hero", "music", "rapper"};
    
    string d6[] = {"business", "inventor", "", "hero", "music", "rapper"};
    
    
    
    
    
    assert(differ(c, 6, d6, 6) == 2); //return 2 because the blank in d differs from c.
    
    
    
    
    
    
    
    
    
    
    
    //Tests for subsequence function
    
    string a1[] = {"india", "china", "mexico", "turkey", "japan", "turkey"};
    
    string a2[] = {"mexico", "turkey", "japan", "turkey"};
    
    
    
    
    
    assert(subsequence(a1, 6, a2, 4) == 2); //return 2 because elements start matching
    
    assert(subsequence(country, -4, people, 4) == -1); //return -1 because illegal array size
    
    assert(subsequence(country, 6, people, -5) == -1); //return -1 because illegal array size
    
    
    
    string b1[] = {"mexico", "turkey", "japan", "turkey"};
    
    string b2[] = {"india", "china", "mexico", "turkey", "japan", "turkey"};
    
    
    
    
    
    assert(subsequence(b1, 4, b2, 6) == -1); //return -1 because b2 bigger than b1
    
    
    
    
    
    string c1[] = {"india", "china", "mexico", "mexico", "turkey", "japan"};
    
    string c2[] = {"mexico", "turkey", "japan", "turkey"};
    
    
    
    assert(subsequence(c1, 6, c2, 4) == -1); //return -1 because not enough room in c1 for all
    
    
    
    
    
    
    
    
    
    
    
    
    
    //Tests for lookupAny function
    
    string d1[] = {"india", "china", "mexico", "turkey", "japan", "turkey"};
    
    string d2[] = {"mexico", "turkey", "india", "turkey"};
    
    
    
    
    
    assert(lookupAny(d1, 6, d2, 4) == 0); //return 0 because first element matchesd1
    
    assert(lookupAny(d1, -4, d2, 4) == -1); //return -1 because illegal array size
    
    assert(lookupAny(d1, 6, d2, -5) == -1); //return -1 because illegal array size
    
    
    
    string e1[] = {"germany", "turkey", "japan", "turkey"};
    
    string e2[] = {"india", "china", "mexico", "turkey", "japan", "turkey"};
    
    
    
    
    
    assert(lookupAny(e1, 4, e2, 6) == 1); //return 1 because turkey matches in both arrays
    
    
    
    
    
    string f1[] = {};
    
    string f2[] = {"turkey"};
    
    
    
    assert(lookupAny(f1, 0 ,f2, 1) == -1); //return -1 because no element in f1 same as f2
    
    
    
    
    
    
    
    string g1[] = {"india", "china", "mexico", "mexico", "turkey", "japan"};
    
    string g2[] = {};
    
    
    
    assert(lookupAny(g1, 6, g2, 0) == -1); //return -1 because no element in g1 is same as g2
    
    
    
    
    
    
    
    string h1[] = {"earth", "mars", "jupiter", "saturn", "mercury", "uranus"};
    
    string h2[] = {"americas", "saturn", "europe", "asia", "aussie", "latinA"};
    
    
    
    assert(lookupAny(h1, 4, h2, 2) == 3); //check for bounded. matching elements at index 3
    
    assert(lookupAny(h1, 5, h2, 6) == 3); //return -1 because array out of bound
    
    assert(lookupAny(h1, 3, h2, 1) == -1); //return -1 because no element in h1 is same as h2
    
    
    
    
    
    
    
    string i1[] = {"earth", "mars", "jupiter", "saturn", "mercury", "uranus"};
    
    string i2[] = {"americas", "jupiter", "europe", "uranus"};
    
    
    
    assert(lookupAny(i1, 6, i2, 4) == 2); //check if lowest index matching returned
    
    //Tests for separate function
    
    string cars[] = {"honda", "toyota", "bmw", "mercedes", "lambo", "tesla", "vw"};
    string blank[] = {"", "", "", "", ""};
    
    assert(separate(cars, 7, "zzz") == 7); //check for last position. greatest sep value
    
    assert(separate(cars, 7, "aston") == 0); //check for first position. least sep value
    
    assert(separate(blank, 3, "") == 0); //check for seperating lowest value. all same. 0 pos.
    
    assert(separate(cars, 0, "ford") == 0); //check bounds. insert in 0 pos because size arr 0
    
    assert(separate(cars, -5, "chevy") == -1); //check for invalid array size
    
    assert(separate(cars, 7, "chevy") == 1); //check for functionality.
    
    //Tests for separate function
    string moreCars[] = {"honda", "toyota", "bmw", "mercedes", "lambo", "tesla", "vw", "chevy"};
    string moreBlank[] = {"", "", "", "", ""};

    assert(separate(moreCars, 8, "zzz") == 8); //check for last position. greatest sep value

    assert(separate(moreCars, 8, "aston") == 0); //check for first position. least sep value

    assert(separate(moreBlank, 3, "") == 0); //check for seperating lowest value. all same. 0 pos.

    assert(separate(moreCars, 0, "ford") == 0); //check bounds. insert in 0 pos because size arr 0

    assert(separate(moreCars, -5, "chevy") == -1); //check for invalid array size

    assert(separate(moreCars, 8, "chevy") == 1); //check for functionality. w
    
    cerr << "great job!" << endl;
    
    
    
    
    //second tests
    //boundary n < 0 cases
    cerr << "n < 0 appendToAll should print -1: " << appendToAll(h, -1, "") << endl;
    cerr << "n < 0 lookup should print -1: " << lookup(h, -1, "") << endl;
    cerr << "n < 0 positionOfMax should print -1: " << positionOfMax(h, -1) << endl;
    cerr << "n < 0 rotateLeft should print -1: " << rotateLeft(h, -1, 4) << endl;
    cerr << "n < 0 countRuns should print -1: " << countRuns(h, -1) << endl;
    cerr << "n < 0 flip should print -1: " << flip(h, -1) << endl;
    cerr << "n < 0 differ should print -1: " << differ(h, -1, g, 4) << endl;
    cerr << "n < 0 differ should print -1: " << differ(h, 7, g, -1) << endl;
    cerr << "n < 0 subsequence should print -1: " << subsequence(h, 7, g, -1) << endl;
    cerr << "n < 0 subsequence should print -1: " << subsequence(h, -1, g, 4) << endl;
    cerr << "n < 0 lookupAny should print -1: " << lookupAny(h, -1, g, 4) << endl;
    cerr << "n < 0 lookupAny should print -1: " << lookupAny(h, 7, g, -1) << endl;
    cerr << "n < 0 separate should print -1: " << separate(h, -1, "gary") << endl;
    
    //appendToAll Test Cases
    cerr << endl << "appendToAll should print 4: " << appendToAll(h, 4, "Hi") << endl;
    printAll(h); cerr << endl;
    cerr << "appendToAll should print 2: " << appendToAll(h, 2, "") << endl;
    printAll(h); cerr << endl;
    cerr << "appendToAll should print 2: " << appendToAll(h, 2, "") << endl;
    printAll(h); cerr << endl;
    
    //lookup test cases
    cerr << endl << "lookup should print -1: " << lookup(h, 7, "JiLL") << endl;
    cerr << "lookup should print 5: " << lookup(h, 7, "jill") << endl;
    cerr << "lookup should print -1: " << lookup(h, 3, "jill") << endl;
    
    //positionOfMax Test Cases
    cerr << endl << "positionOfMax should print 6: " << positionOfMax(h, 7) << endl;
    cerr << "positionOfMax should print 3: " << positionOfMax(h, 4) << endl;
    cerr << "positionOfMax should print -1: " << positionOfMax(h, 0) << endl;
    
    //rotateLeft Test Cases
    cerr << endl << "rotateLeft should print 6: " << rotateLeft(h, 7, 6) << endl;
    printAll(h); cerr << endl;
    cerr << "rotateLeft should print -1: " << rotateLeft(h, 4, 4) << endl;
    printAll(h); cerr << endl;
    cerr << "rotateLeft should print -1: " << rotateLeft(h, 0, 3) << endl;
    printAll(h); cerr << endl;
    cerr << "rotateLeft should print 3: " << rotateLeft(h, 7, 3) << endl;
    printAll(h); cerr << endl;
    
    //countRuns Test Cases
    cerr << endl<< "countRuns should print 7: " << countRuns(h, 7) << endl;
    cerr << "countRuns should print 0: " << countRuns(h, 0) << endl;
    string m[2] = { "hi", "hi" };
    cerr << "countRuns should print 1: " << countRuns(m, 2) << endl;
    
    //flip Test cases
    cerr << endl;
    cerr << "flip should print 4: " << flip(h, 4) << endl;
    printAll(h); cerr << endl;
    cerr << "flip should print 7: " << flip(h, 7) << endl;
    printAll(h); cerr << endl;
    
    //differ test cases
    cerr << endl;
    string gram[4] = {"garyHi", "tim", "Jill", "Hi"};
    cerr << "differ should print 2: " << differ(h, 7, gram, 4) << endl;
    string j[7] = {"garyHi", "tim", "jill", "Hi", "donaldHi", "evanHi", "hillary"};
    cerr << "differ should print 7: " << differ(h, 7, j, 7) << endl;
    cerr << "differ should print 3: " << differ(h, 3, j, 7) << endl;
    
    //subsequence test cases
    
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
