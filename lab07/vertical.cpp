/* Skeleton file for vertical.cpp
 * For use in CS16
 * (c) 2024 by Z.Matni
 */
// Do not add any other #include statement!
#include <iostream>
using namespace std;

// Declare printV() here
void printV(long val);
    //Preconditions: Takes in an integer value
    //Postconditions: Prints the integer value vertically, meaning it starts with the most sig digit and ends with the least significant digit

int main() {
    // 1. Get user input
    // 2. Check input and pass it on to printV()
    long value; //variable creation
    cout << "Enter integer: ";//user prompt
    cin >> value; //user input
    if(value < 0){ //if the value is negative, then throw an error
        cerr << "Input must be a positive integer.\n";
        return 0;
    }
    printV(value); //recursively print verticall all numbers at each digit place
    return 0; //main return
}

// Define printV() here
//
void printV(long val){
    if(val >= 10){ //if the value is greater than or equal to 10, recursively call again with the value divded by 10
        printV(val / 10);
    }
    cout << val % 10 << endl; //base case, when the val is no longer divisible by 10, (or at least give a remainder less than 1), print that remainder w/modulo division
}
