#include<bits/stdc++.h>
using namespace std;

// Approach - 1 -> use hash map
// Time Complexity -> O(nlog(n)
void printDuplicates(string s) {
    map<char, int> mp;
    
    for(int i=0; i<s.length(); i++) {
        mp[s[i]]++;
    }
    
    for(pair<char, int> i: mp) {
        if(i.second > 1) {
            cout<<i.first<<" - "<<i.second<<endl;
        }
    }
}

int main() {
    string s="";
    cout<<"Enter the String: "<<endl;
    cin>>s;
    
    printDuplicates(s);
    return 0;
}


// Approach - 2 -> use array to store count values
// Time Complexity -> O(n)

int main() {
    string str;
    
    cout<<"Enter string: "<<endl;
    cin>>str;
    
    int count[26] = {0};
    
    for(int i=0; i<str.length(); i++) {
        count[str[i] - 'a']++;
    }
    
    for(int i=0; i<26; i++) {
        if(count[i] > 1) {
            cout<<char(i + 'a')<<" - "<<count[i]<<endl;
        }
    }
    
    return 0;
}