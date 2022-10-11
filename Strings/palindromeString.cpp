#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string S) {
    int s = 0;
    int e = S.length()-1;
    
    while(s < e) {
        if(S[s] == S[e]) {
            s++;
            e--;
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main() {
    string s;
    cout<<"Enter the String: "<<endl;
    cin>>s;
    
    cout<<"If it is valid print 1 else 0: "<<endl;
    cout<<isPalindrome(s)<<endl;
    
    return 0;
}