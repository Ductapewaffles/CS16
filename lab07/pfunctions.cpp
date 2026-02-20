// File: pfunctions.cpp
#include <iostream>
#include <string> 
using namespace std;

#include "pheaders.h"

// DEFINE THE 2 FUNCTIONS PER THE pheaders.h FILE HERE
// Add Pre- and Post-Condition comments


bool isPalindrome(string s){
    if (s.size() <= 1){ //sees if the updates size is less than or equal to 1, which means that all other letters are the same on opposite sides of the word (palindrome)
        return true; //if so return true (this is the base case)
    }
    if(s[0] != s[s.size() - 1]){ //if the first index does not equal the last index
        return false; //return false (not the same letters on either sides of the word
    }
    s.erase(0,1); //erase the first index
    s.erase(s.size() - 1, 1); //erase the updated last index
    return isPalindrome(s); //recursively call the function again
}

void cleanUp(string &s) {
    //Preconditions: Takes in a reference to a string
    //Postconditions: gets rid of any non-alphabetic characters within the string and makes every character in the string lowercase
    int size = s.size(); //get the size of the original string
    string cleaned(""); //variable initialization
    for(int i = 0; i < size; i++){ //iterate through all characters in string
        if(isalpha(s[i])){ //if the given character is alphabetic, then d it to the cleaned string as the lowercase
            cleaned += tolower(s[i]);
        }
    }
    s = cleaned; //set the original string equal to the cleaned string
    return;
}

