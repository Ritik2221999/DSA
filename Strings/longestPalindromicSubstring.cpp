#include<bits/stdc++.h>
using namespace std;

void printString(string s, int start, int end) {
    for(int i=start; i<=end; i++) {
        cout<<s[i];
    }
}

void longestPalin(string s) {
    int low, high;
    
    int start = 0, end = 1;
    
    for(int i=1; i<s.length(); i++) {
        // for even substring
        low = i-1;
        high = i;
        
        while(low >= 0 && high < s.length() && s[low] == s[high]) {
            
            // find the starting and ending of current substring
            if(high - low + 1 > end)  // if length of new substring is greater than previous substring 
            {
                start = low;
                end = high-low+1;
            }
           low--; // move to leftwards
           high++;  // move to rightwards
        }
        
    
        // odd substring
        low = i-1;
        high = i+1;
        
        while(low >= 0 && high < s.length() && s[low] == s[high]) {
           if(high - low + 1 > end) {
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }
    }
    printString(s, start, start+end-1);
}

int main() {
    string s="aaaabbaa";
    
    cout<<"The longest palindromic substring is: "<<endl;
    longestPalin(s);
    return 0;
}
