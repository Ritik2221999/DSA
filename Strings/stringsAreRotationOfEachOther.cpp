#include<iostream>
using namespace std;

bool checkRotation(string str1, string str2) {
    if(str1.length() != str2.length())
        return false;
        
    string temp = str1+str2;
    
    int n = temp.length();
    int m = str2.length();
    
    // check if s2 is present in temp
    for(int i=0; i<n; i++) {
        int flag = 1;
        for(int j=0; j<m; j++) {
            if(str2[j] != temp[i+j]) {
                flag = 0;
                break;
            }
        }
        
        if(flag == 1)
            return true; // if s2 is present in temp
    }
    return false;
}

int main() {
    string str1 = "hello", str2 = "lohel";
    if(checkRotation(str1, str2)) {
        cout<<"The strings are rotation of each other: "<<endl;
    }
    else {
        cout<<"The strings are not rotation of each other: "<<endl;
    }
    return 0;
}