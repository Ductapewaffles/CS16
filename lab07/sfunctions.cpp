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
    int index(0); //variable initialization --> incrementing this value to return
    int largest_temp; //variable creation for ascending order
    int smallest_temp; //variable creation for descending order

    if(!desc){ //if put in ascending order
        largest_temp = a[start_index]; //we make the first largest integer as the first element 
        index = start_index; //index is start index (0)
        for(int i = start_index + 1; i < number_used; i++){ //iterate throughout the entire array
            if(largest_temp < a[i]){ //if the previous value is smaller than the value at current index
                largest_temp = a[i]; //make that value the "largest"
                index = i; //if that was the largest one throughout the array, the index will be of the largest number
            }
        }
    }
    else if (desc){ //if put in descending order
        smallest_temp = a[start_index]; //we make the first smallest integer as the first element
        index = start_index; //index is start index (0)
        for(int i = start_index + 1; i < number_used; i++){ //iterate throughout all element of array
            if(smallest_temp > a[i]){ //if there is a value smaller than the current smallest
                smallest_temp = a[i]; //make the smallest that value
                index = i; //record the index of the current smallest value within the array
            }
        }
    }
    return index; //return the recorded index of largest/smallest depending on specification
}

void swap_values(int &val1, int &val2){
    //Preconditions: Takes in two integers which are passed by reference
    //Postconditions: Switches the values at the respective addresses so that their values have been swapped
    int temp; //variable creation
    temp = val2; //set the temporary value to the value of val2
    val2 = val1; //swap val2 to val1
    val1 = temp; //then swap val1 to the temp (which holds the original value of val2)
    return; //function return
}

void sort(bool desc, int a[], int number_used, int index){
    //Preconditions: Takes in a boolean value to determine if sorting in descending (true), an integer array,
    //the amount of numbers that we want to use within the array, and the starting index for the sorting (should
    //be 0 for pretty much all cases)
    //Postconditions: Sorts the array in descending or ascending order based on the value of the boolean desc variable.
    //True if you want descending and false if you want ascending
    if(number_used <= 1){ //recursive base case 
        return; 
    }
    int index_found; //variable creation
    int value_1, value_2; //variable creation
    if(!desc){ //if specified as ascending order
        index_found = find_index_of_swap(desc, a, index, number_used); //get the index where the largest value was found
        value_1 = a[index_found]; //set value_1 to the largest value within the array
        value_2 = a[number_used - 1]; //set value_2 to the last element in the array
        swap_values(a[number_used - 1], a[index_found]); //swap the two values so now the largest value is the last element of the array
        number_used--; //decrement the amount of numbers in use so that the largest value will now remain at the largest index
        sort(desc, a, number_used, index); //call sort recursively again
    }
    else if (desc){ //if specified as descending order
        index_found = find_index_of_swap(desc, a, index, number_used); //set the index_found variable to the index of the smallest integer in the array
        swap_values(a[number_used - 1], a[index_found]); //swap the values so that the smallest value is now at the largest index
        number_used--; //decrement the amount of integers in use so that the largest value will now remain at the largest index
        sort(desc, a, number_used, index); //call sort recursively again
    }
    return;
}

int getFileSize(ifstream &object, string file_name){
    //Preconditions: ifstream objects and string file name
    //Postconditions: count the number of integers within the file (file size)
    object.open(file_name); //open the connection to the specified file
    int count(0), next; //variable initialization
    while(object >> next){ //go until the end of the file
        count++; //increment the count for every instance of an integer in the object file
    }
    object.close(); //close the connection once the end of the file is reached
    return count; //return the count of integers within the file
}

void getArray(ifstream &object, string file_name, int arr[], int array_size){
    //Preconditions: Takes in the ifstream object, the filename that we are pulling from, an integer array, and the size of that array
    //Postconditions: Gets all values from the file and puts them into the array given
    object.open(file_name); //open the connection to the specified file
    int next; //variable creation
    int index_array(0); //variable creation
    while(object >> next){
        arr[index_array] = next; //for each respective index of the array, insert a value from the ifstream object file
        index_array++; //increment the index of insertion so that each value from the file is inserted at a different index until the end of the file
    }
    object.close(); //close the connection to the file
    return; //return
}


