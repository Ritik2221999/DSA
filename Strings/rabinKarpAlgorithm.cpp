#include<bits/stdc++.h>
using namespace std;

void rabinKarp(string &text, string &pattern) {
    int m = pattern.length(); 
    int n = text.length();
    int q = 128;
    int x = 1; // typically prime - multiplier
    int x_m = 1; // x^(m-1) used for next hash computation
    int hash_Patt = 0;
    int hash_Text = 0;
    
    for(int i=0; i<m-1; i++) {
        x_m = (x_m*x)%q;
    }
    
    // hash of pattern and first windowof text string
    for(int i=0; i<m; i++) {
        hash_Patt = (hash_Patt*x + pattern[i])%q;
        hash_Text = (hash_Text*x + text[i])%q;
    }
    
    for(int i=0; i<n-m+1; i++) {
        if(hash_Text == hash_Patt) {
            bool found = true;
            // character by character match
            for(int j=0; j<m; j++) {
                if(text[i+j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            
            if(found)
                cout<<"Match at index: "<<i<<endl;
        }
        // if it was not last window, then continue hash computation
        if(i < n-m) {
            hash_Text = (x*(hash_Text - text[i]*x_m) + text[i+m])%q;
            if(hash_Text < 0)
                hash_Text += q;
        }
    }
}

int main() {
    string text;
    cout<<"Enter the text: "<<endl;
    cin>>text;
    
    string pattern;
    cout<<"Enter the pattern: "<<endl;
    cin>>pattern;
    
    rabinKarp(text, pattern);
    
    return 0;
}