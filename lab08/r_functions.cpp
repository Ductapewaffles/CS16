// file: r_functions.cpp
// YOUR NAME HERE
// Define the functions, per the list in r_headers.h
const string OUTPUTFILE = "Results.txt";

void NameSort(UndergradStudents array[], int size){
    //Preconditions: Takes in an array of type UndergradStudents and the size of that array
    //Postconditions: Sorts elements of the array according to the alphabetical order of the last member function's variable within each element
    for(int i = size - 1; i >= 0; i--){ //the bubble sort syntax but instead if the first char of the last name is further down the alphabet, then switch
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
    //Preconditions: Takes in an array of type UndergradStudents and the size of the array by reference
    //Postconditions: Uses user input to add values for each student that the user has
    int count(0);
    int id_num(0);
    cout << showpoint;
    cout << setprecision(2); //set to 2 decimal places
    for(int i = 0; i < 20; i++){ //loop to get all the entries from the user (20 maximum entries)
        string first;
        if(i != 0){ //formatting
            cout << endl;
        }
        cout << "Student 0" << count + 1 << ":Enter first name (or x to quit): "; //user prompt with the respective student number (starts at Student 01)
        cin >> first;
        if(first == "x" || first == "X"){ //if the user chooses to quit, then exit the for loop
            break;
        }
        count++; //increment the count as this is the next student 
        id_num++; //increment the id_num for the respective student
        us[i].first = first; //the structure at the ith index now has the user entered first name
        string last, major; 
        float GPA1, GPA2, GPA3, GPA4;
        cout << "Student 0" << count << ":Enter last name: "; //prompt to get last name
        cin >> last;
        cout << "Student 0" << count << ":Enter major: "; //prompt to get major
        cin >> major;
        cout << "Student 0" << count << ":Enter GPA Year 1: "; //prompt to get 1st GPA
        cin >> GPA1;
        cout << "Student 0" << count << ":Enter GPA Year 2: "; //prompt to get 2nd GPA
        cin >> GPA2;
        cout << "Student 0" << count << ":Enter GPA Year 3: "; //prompt to get 3rd GPA
        cin >> GPA3;
        cout << "Student 0" << count << ":Enter GPA Year 4: "; //prompt to get 4th GPA
        cin >> GPA4;
        us[i].last = last; //add the last name to the structure at the ith index
        us[i].major = major; //add the major to the structure at the ith index
        double average = (GPA1 + GPA2 + GPA3 + GPA4) / 4; //average GPA among the four years
        us[i].GPA_avg = average; //add the average GPA to the structure at the ith index
        us[i].ID_num = id_num; //add the student ID to the structure at the ith index
    }
    size = count; //change the size of the array to the count of structures made within the for loop (maximum 20)
}
   
void WriteResults(ofstream &outf, UndergradStudents us[], int size){
    //Preconditions: Takes in the name of the outfile, the array of structures(student information), and the size of the array
    //Postconditions: Prints out the respective information for each student
    outf.open(OUTPUTFILE); //open the outFile
    if(outf.fail()){ //if the output File fails to open, send an error
        cerr << "Failed to open output file";
        exit(1);
    }
    outf << "These are the results sorted by last name:\n"; 
    NameSort(us, size); //sorts the structures by the alphabetical order of last names
    for(int i = 0; i < size; i++){ //gives the number of outputs for the number of students
        outf << "ID #" << us[i].ID_num << ": "; //outputs student ID
        outf << us[i].last << ": "; //outputs student last name
        outf << us[i].first << ": "; //outputs student first name
        outf << us[i].major << ": "; //outputs student major
        outf << us[i].GPA_avg << endl; //outputs student average GPA
    }
    outf.close(); //close connection to the out file
    return;
}


