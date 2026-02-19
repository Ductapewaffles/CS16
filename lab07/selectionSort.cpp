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
    string filename_1;
    cout << "Enter filename: ";
    cin >> filename_1;
    ifstream inFile;
    inFile.open(filename_1);
    if(inFile.fail()){
        cerr << "Could not open file" << endl;
        exit(1);
    }
    inFile.close();
    int fileSize = getFileSize(inFile, filename_1);
    p1 = new int[fileSize];
    cout << "Original array:\n";
    getArray(inFile, filename_1, p1, fileSize);
    for(int i = 0; i < fileSize; i++){
        cout << p1[i] << " ";
    }
    cout << endl;
    int file_size_o = fileSize;
    bool cend;
    cout << "Ascending (0) or Descending (1): ";
    cin >> cend;
    sort(cend, p1, fileSize, 0);
    cout << "Sorted array:\n";
    for(int i = 0; i < file_size_o; i++){
        cout << p1[i] << " ";
    }
    cout << endl;
    return 0;
}
