#include<bits/stdc++.h>
using namespace std;

int countRev(string str) {
    
    // if str is of odd length, it can't be balanced
    if(str.length() & 1)
        return -1;
        
    int reversals = 0; // stores total reversals needed
    int open = 0; //stores total no of opening braces
    
    for(int i=0; i<str.length(); i++) {
        // if current char is opening braces
        if(str[i] == '{')
            open++;
        
        else {  // if current character is closing braces
        
            // if an opening brace is found before, close it
            if(open)
                open = open - 1;
            else { // invert the closing brace i.e. '}' to '{'
                reversals++;
                open = 1; // incermement open brace count
            }
        }
    }
    // for 'n' opened braces, exactly n/2 reversala are needed
    return reversals + open/2;
}

int main() {
    string str = "}{{}}{{{";
    cout<<"Total reversals needed to make a balanced expression is: "<<endl;
    cout<<countRev(str);
    return 0;
}