// File: pfunctions.cpp
#include <iostream>
#include <string> 
using namespace std;

#include "pheaders.h"

// DEFINE THE 2 FUNCTIONS PER THE pheaders.h FILE HERE
// Add Pre- and Post-Condition comments


bool isPalindrome(string s) {
    //Preconditions: takes in a string that has been cleaned
    //Postconditions: Returns true if the string is a palindrome and false otherwise. Recursively calls itself
    if(s == ""){ //if the string is empty, then return true (means that it is a palindrome
        return true;
    }
    int size1 = s.size(); //update size1 value
    if(size1 % 2 != 0){ //this is for strings who have an odd number of characters
        if(s[0] == s[size1 - 1]){ //if the first and last element are equal
            s.erase(0, 1); //delete first element
            s.erase(s.size() - 1, 1); //delete last element
            if(s.size() == 1){ //if the size is 1, meaning there should only be the middle character remaining after all other have been compared, then return true
                return true;
            }
            return isPalindrome(s); //otherwise, recursively call the isPalindrome() function
        }
        return false; //if one of the first and last indices is not the same, then return false
    }
    else if(size1 % 2 == 0){ //if the number of characters is even within the cleaned string
        if(s[0] == s[size1 - 1]){ //if the first and last element are the same
            s.erase(0,1); //delete first char
            s.erase(s.size() - 1, 1); //delete last char
            if(s.size() == 0){ //if the size is zero (which means all chars have been successfully deleted, then return true
                return true;
            }
            return isPalindrome(s); //recursively call again if this is not the case
        }
        return false; //return false if the first and last index chars are not the same for any given iteration 
    }
    return false;
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

