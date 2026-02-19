#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


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
        index = start_index;
        for(int i = start_index + 1; i < number_used; i++){
            if(largest_temp < a[i]){
                largest_temp = a[i];
                index = i;
            }
        }
    }
    else if (desc){
        smallest_temp = a[start_index];
        index = start_index;
        for(int i = start_index + 1; i < number_used; i++){
            if(smallest_temp > a[i]){
                smallest_temp = a[i];
                index = i;
            }
        }
    }
    return index;
}


void swap_values(int &val1, int &val2){
    //Preconditions: Takes in two integers which are passed by reference
    //Postconditions: Switches the values at the respective addresses so that their values have been swapped
    int temp;
    temp = val2;
    val2 = val1;
    val1 = temp;
    return;
}
void sort(bool desc, int a[], int number_used, int index){
    index = 0;
    if(number_used <= 1){
        return;
    }
    int index_found;
    int value_1, value_2;
    if(!desc){
        index_found = find_index_of_swap(desc, a, index, number_used);
        value_1 = a[index_found];
        value_2 = a[number_used - 1]; //last index of the array
        swap_values(a[number_used - 1], a[index_found]);
        number_used--;
        sort(desc, a, number_used, index); 
    }
    else if (desc){
        index_found = find_index_of_swap(desc, a, index, number_used);
        swap_values(a[number_used - 1], a[index_found]);
        number_used--;
        sort(desc, a, number_used, index);
    }
    return;
}

int getFileSize(ifstream &object, string file_name){
    //Preconditions: ifstream objects and string file name
    //Postconditions: count the number of integers within the file (file size)
    object.open(file_name);
    int count(0), next;
    while(object >> next){
        count++;
    }
    object.close();
    return count;
}

void getArray(ifstream &object, string file_name, int arr[], int array_size){
    object.open(file_name);
    int next;
    int index_array(0);
    while(object >> next){
        arr[index_array] = next;
        index_array++;
    }
    object.close();
    return;
}





int main(){
    typedef int* IntegerPtr;
    IntegerPtr p1 = nullptr;
    ifstream inFile;
    string array_file;
    cout << "Enter a filename: ";
    cin >> array_file;
    int file_size = getFileSize(inFile, array_file);
    p1 = new int[file_size];
    getArray(inFile, array_file, p1, file_size);
    for(int i = 0; i < file_size; i++){
        cout << p1[i] << " ";
    }
    //cout << endl;
    //cout << find_index_of_swap(false, array, 0, 8) << endl;
    //cout << find_index_of_swap(true, array, 0, 8) << endl;
    int value1 = 7;
    int value2 = 10;
    //swap_values(value1, value2);
    //cout << value1 << " should be 10" << endl;
   // cout << value2 << " should be 7" << endl;
    //sort(false, array, 8, 0);
    //for(int i = 0; i < 8; i++){
    //    cout << array[i] << " ";
    //}
   // cout << endl;
    delete []p1;
    p1 = nullptr;
    return 0;
}
