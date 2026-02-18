/* Main function for palindrome.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <string>   // for string
using namespace std;
#include "pheaders.h"

int main() {
    string sentence;
    cout << "Enter sentence:\n";
    getline(cin, sentence);
    cleanUp(sentence);
    if(isPalindrome(sentence)){
        cout << "It is a palindrome.\n";
    }
    else{
        cout << "It is not a palindrome.\n";
    }
    // 1. Get a string from the user (see examples given)
    // 2. Clean up the string using the required function
    // 3. Check to see if string is a palindrome
    // 4. Print out message accordingly (see examples given)

    return 0;
}

