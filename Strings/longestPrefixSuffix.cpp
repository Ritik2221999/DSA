#include<bits/stdc++.h>
using namespace std;

int lps(string s) {
	    // Your code goes here
    int n = s.length();
    int len = 0;
    vector<int> lps(n);
    lps[0] = 0;
    
    int i = 1;
    
    while(i < n) {
        if(s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return len;
    
}

int main() {
    string pat = "aaaa";
    
    cout<<"length is: "<<lps(pat)<<endl;
    
    return 0;
}