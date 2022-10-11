#include<bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars) {
    int i=0;
    int ansIndex = 0;
    int n = chars.size();
    
    while(i < n) {
        int j = i+1;
        
        // you will exit this loop only when
        // 1.) you have traverse the whole vector
        // 2.) or you have discovered the new element
        while(j < n && chars[i] == chars[j]) {
            j++;
        }
        
        // store the old character
        chars[ansIndex++] = chars[i];
        
        int count = j - i; // how many same characters you got, save in count
        
        if(count > 1) {
            string str = to_string(count);  // converting count into single digit and saving in string
            for(char ch: str) {
                chars[ansIndex++] = ch;  // strong the count of old character
            }
        }
        // moving to new character
        i = j;
    }
    return ansIndex;
}

int main() {
    vector<char> chars ({'a','a','b','b','c','c','c'});
    
    cout<<compress(chars)<<endl;
    
    for(int i=0; i<chars.size()-1; i++) {
        cout<<chars[i]<<" ";
    }cout<<endl;
    return 0;
}