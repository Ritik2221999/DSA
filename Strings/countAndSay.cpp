#include<iostream>
using namespace std;

string countAndSay(int n) {
    if(n == 1) return "1";
    if(n == 2) return "11";
    string s = "11";
    
    for(int i=3; i<=n; i++) {
        string temp = "";
        s = s + "&";
        int count = 1;
        
        for(int j = 1; j<s.length(); j++) {
            if(s[j] != s[j-1]) {   // if current and previous element is not same
                temp = temp + to_string(count);  // string how many times element appears
                temp = temp + s[j-1]; // storing the element
                count = 1;
            }
            else count++;
        }
        s = temp;
    }
    return s;
}

int main() {
    int n;
    cout<<"Enter the Number of elements: "<<endl;
    cin>>n;
    
    cout<<countAndSay(n);
    return 0;
}