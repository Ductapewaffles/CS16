// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"

// DEFINE ALL 5 FUNCTIONS PER THE sheaders.h FILE HERE
// Add Pre- and Post-Condition comments

int find_index_of_swap(bool desc, int a[], int start_index, int number_used){
    //Preconditions: Takes in a boolean which if true, makes the swapping go in the descending direction
    //and if false sorts in the ascending direction. Also takes in an integer array that has all
    //the values that need to be sorted, and integer for the starting index, and an integer for the numbers used
    //which should be incremented outside of this function for optimal performance
    //Postconditions: Looks for the index of the largest (or smallest depending on the boolean value for desc) integer value within the array and returns that index.
    //
    int index(0);
    int largest_temp;
    int smallest_temp;

    if(!desc){ //if put in ascending order
        largest_temp = a[start_index];
        for(int i = start_index + 1; i < number_used; i++){
            if(largest_temp < a[i]){
                largest_temp = a[i];
                index = i;
            }
        }
    }
    else if (desc){
        smallest_temp = a[start_index];
        for(int i = start_index + 1; i < number_used; i++){
            if(smallest_temp < a[i]){
                smallest_temp = a[i]
                index = i
            }
        }
    }
    return index;
}
