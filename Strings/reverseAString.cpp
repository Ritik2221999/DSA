#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

// Approach -> 1 (Two Pinter Approach)

void reverse(char name[], int n) {
    int start = 0;
    int end = n-1;
    
    while(start <= end) {
        swap(name[start++], name[end--]);
    }
}

int main() {
    char name[20];
    cout<<"Enter the String: "<<endl;
    cin>>name;
    
    int n = strlen(name);
    reverse(name, n);
    
    cout<<"string after reversing: "<<endl;
    cout<<name<<endl;
    return 0;
}

// *****************************************************************************

// Approach -> 2 (using STL function)

int main() {
    string name="";
    
    cout<<"Enter the String to be reversed: "<<endl;
    getline(cin, name);
    
    reverse(name.begin(), name.end());
    
    cout<<"The reversed string is: "<<endl;
    cout<<name<<endl;
    
    return 0;
}

// ******************************************************************************

// Approach -> 3 (iterstive approach)

void reverse(string name) {
    int nameLength = name.length();
    
    while(nameLength >= 0) {
        cout<<name[nameLength];
        --nameLength;
    }
}

int main() {
    string name="";
    
    cout<<"Enter the String to be reversed: "<<endl;
    getline(cin, name);
    
    cout<<"The reversed string is: "<<endl;
    reverse(name);
    cout<<endl;
}