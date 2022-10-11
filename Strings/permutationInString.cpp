#include<bits/stdc++.h>
using namespace std; 

bool checkEqual(int arr1[26], int arr2[26]) {
    for(int i=0; i<26; i++) {
        if(arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}

bool checkInclusion(string str1, string str2) {
    int count1[26] = {0};
    
    //         character count array of each element in s1
    for(int i=0; i<str1.length(); i++) {
        int index = str1[i] - 'a';
        count1[index]++;
    }
    
    //         traverse s2 string in window of size s1 length and compare
    int i=0;
    int windowSize = str1.length();
    int count2[26] = {0};
    
    //         running for first window -> and incrementing the word by 1 to see its frequency
    while(i < windowSize && i< str2.length()) {
        int index = str2[i] - 'a';
        count2[index]++;
        i++;
    }
    
    if(checkEqual(count1, count2))
        return 1;
     
    //         move to next window   
    while(i<str2.length()) {
        char newChar = str2[i];  // this will point to the 2nd element of new window if window size is 2
        int index = newChar - 'a';  // this will convert to number  
        count2[index]++;  // inc the value of new character by 1
        
        
    //    this will point to the character which we leave while moving to new window
        char oldChar = str2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;  // make the count of old element to zero
        
        i++;
        
        if(checkEqual(count1, count2))
            return 1;
    }
    return 0;
}

int main() {
    
    string str1 = "ab";
    string str2 = "eidbaooo";
    
    if(checkInclusion(str1, str2)) {
        cout<<"permutation of string-1 is present in string-2: "<<endl;
    }
    else {
        cout<<"permutation of string-1 is not present in string-2: "<<endl;
    }
    
    return 0;
}