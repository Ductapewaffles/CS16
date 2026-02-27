#include <iostream>
using namespace std;



struct UndergradStudents{
    string first;
    string last;
    string major;
    float GPA_1;
    float GPA_2;
    float GPA_3;
    float GPA_4;
};








void NameSort(UndergradStudents array[], int size){
    //Preconditions: Takes in an array of type UndergradStudents and the size of that array
    //Postconditions: Sorts elements of the array according to the alphabetical order of the last member function's variable within each element
    for(int i = size - 1; i >= 0; i--){
        for(int j = 1; j <= i; j++){
            string temp1 = array[j-1].last;
            string temp2 = array[j].last;
            if(temp1[0] > temp2[0]){
                UndergradStudents temp_i = array[j-1];
                array[j-1] = array[j];
                array[j] = temp_i;
            }
        }
    }
}
void InitializeStructures(UndergradStudents us[], int &size){
    int count(0);
    for(int i = 0; i < 20; i++){
        string first;
        if(i != 0){
            cout << endl;
        }
        cout << "Student 0" << count + 1 << ":Enter first name (or x to quit): ";
        cin >> first;
        if(first == "x" || first == "X"){
            break;
        }
        count++;
        us[i].first = first;
        string last, major;
        float GPA1, GPA2, GPA3, GPA4;
        cout << "Student 0" << count << ":Enter last name: ";
        cin >> last;
        cout << "Student 0" << count << ":Enter major: ";
        cin >> major;
        cout << "Student 0" << count << ":Enter GPA Year 1: ";
        cin >> GPA1;
        cout << "Student 0" << count << ":Enter GPA Year 2: ";
        cin >> GPA2;
        cout << "Student 0" << count << ":Enter GPA Year 3: ";
        cin >> GPA3;
        cout << "Student 0" << count << ":Enter GPA Year 4: ";
        cin >> GPA4;
        us[i].last = last;
        us[i].major = major;
        us[i].GPA_1 = GPA1;
        us[i].GPA_2 = GPA2;
        us[i].GPA_3 = GPA3;
        us[i].GPA_4 = GPA4;
    }
    size = count;
}
   
int main(){
    const int MAX = 20;
    int size = 0;
    UndergradStudents arr[MAX];
    InitializeStructures(arr, size);
    for(int i = 0; i < size; i++){
        cout << arr[i].first << endl;
        cout << arr[i].last << endl;
        cout << arr[i].major << endl;
        cout << arr[i].GPA_1 << endl;
        cout << arr[i].GPA_2 << endl;
        cout << arr[i].GPA_3 << endl;
        cout << arr[i].GPA_4 << endl;
    }
    return 0;
}
