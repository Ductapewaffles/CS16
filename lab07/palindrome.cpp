/* Main function for palindrome.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <string>   // for string
using namespace std;
#include "pheaders.h"

int main() {
    string sentence; //variable creation
    cout << "Enter sentence:\n"; //user prompt 
    getline(cin, sentence); //get use the getline function to get the input of one line
    cleanUp(sentence); //cleanup that line
    if(isPalindrome(sentence)){ //determine if the sentence is a palindrome
        cout << "It is a palindrome.\n"; //if it is a palindrome
    }
    else{ //otherwise
        cout << "It is not a palindrome.\n";
    }
    // 1. Get a string from the user (see examples given)
    // 2. Clean up the string using the required function
    // 3. Check to see if string is a palindrome
    // 4. Print out message accordingly (see examples given)

    return 0; //main return
}

