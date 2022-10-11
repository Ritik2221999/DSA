#include<bits/stdc++.h>
using namespace std;

bool isPalindromeHelper(int left, int right, string &s) {
    // base case
    if(left >= right) return true;
    if(s[left] != s[right])
        return false;
    return isPalindromeHelper(left+1, right-1, s);
}

bool isPalindrome(string &s) {
    return isPalindromeHelper(0, s.size()-1, s);
}

int main() {
    string str;
    cout<<"Enter the palindromic string: "<<endl;
    cin>>str;
    
    if(isPalindrome(str)) {
        cout<<"string is palindrome: \n";
    }else
        cout<<"String is not a palindrome: "<<endl;
    return 0;
}