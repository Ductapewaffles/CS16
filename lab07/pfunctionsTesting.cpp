#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

void cleanUp(string &s) {
    int size = s.size();
    string cleaned("");
    for(int i = 0; i < size; i++){
        if(isalpha(s[i])){
            cleaned += tolower(s[i]);
        }
    }
    s = cleaned;
    cout << s << endl; // This is a TRACE - remove it once the function is completed. 
}

bool isPalindrome(string s) {
    if(s == ""){
        return true;
    }
    int size1 = s.size();
    if(size1 % 2 != 0){ //this is for strings who have an odd number of characters
        if(s[0] == s[size1 - 1]){
            s.erase(0, 1);
            s.erase(s.size() - 1, 1);
            if(s.size() == 1){
                return true;
            }
            return isPalindrome(s);
        }
        return false;
    }
    else if(size1 % 2 == 0){
        if(s[0] == s[size1 - 1]){
            s.erase(0,1);
            s.erase(s.size() - 1, 1);
            if(s.size() == 0){
                return true;
            }
            return isPalindrome(s);
        }
        return false;
    }
}

int main(){
    string s1 = "Madam, I'm Adam";
    cleanUp(s1);
    cout << s1 << endl;
    cout << isPalindrome(s1) << endl;
}
