/* Main function for selectionSort.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit
using namespace std;
#include "sheaders.h"

typedef int* IntegerPtr;
IntegerPtr p1 = nullptr;
int main() {
    // 1. Get filename from user and check it
    // 2. Get size of file to then create dynamic array
    //      Note: You HAVE to use the functions:
    //      getFileSize() and getArray() here
    // 3. Print original array (see PDF lab description for details)
    // 4. Ask user for ascending or descending sort
    // 5. Run selection sort on the array
    //      Note: You HAVE to use the function sort() here
    // 6. Print sorted array (see PDF lab description for details)
    string filename_1; //variable initialization
    cout << "Enter filename: "; //user prompt
    cin >> filename_1; //user input 
    ifstream inFile; //creating the ifstream object
    inFile.open(filename_1); //open the user specified object file
    if(inFile.fail()){ //if the file fails to connect then execute an error
        cerr << "Could not open file" << endl;
        exit(1);
    }
    inFile.close(); //close the connection to the object file
    int fileSize = getFileSize(inFile, filename_1); //use the getFileSize function to get the size of the file
    p1 = new int[fileSize]; //dynamic array creation with the number of integers in the file
    cout << "Original array:\n"; //prompt to print the original array
    getArray(inFile, filename_1, p1, fileSize); //using the getArray function to input every integer from the object file into the newly created dynamic array
    for(int i = 0; i < fileSize; i++){ //for loop to print out every element of the array
        cout << p1[i] << " ";
    }
    cout << endl; //a newline character to start on the next line for the next prompt
    int file_size_o = fileSize; //temporary file size
    bool cend; //variable creation
    cout << "Ascending (0) or Descending (1): "; //user prompt
    cin >> cend; //user input for descending or ascending
    sort(cend, p1, fileSize, 0); //sort the file based on the user specified ascending or descending order
    cout << "Sorted array:\n"; //prompt to print the sorted array
    for(int i = 0; i < file_size_o; i++){ //for every element in the sorted array, print it out
        cout << p1[i] << " ";
    }
    cout << endl; //newline after the entire outputted array
    return 0; //main return
}
