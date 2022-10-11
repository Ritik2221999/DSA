// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1#

#include<bits/stdc++.h>
using namespace std;

string secFrequent(string arr[], int n) {
    int maxFreq = 0;
    string s = "";
    
    // put all the strings in map with its count ans also keep track of max number of times occured string
    unordered_map<string, int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
        if(mp[arr[i]] > maxFreq) {
            maxFreq = mp[arr[i]]; // contains the maximum frequency
            s = arr[i];  // contains the string having maximum frequency
        }
    }
    
    // delete the string which occured max no. of times and make frequency to 0
    mp.erase(s);
    string ans = "";
    maxFreq = 0;
    
    // now put the max string in ans because ,that string is second max as we deleted first max string 
    for(auto it: mp) {
        if(it.second > maxFreq) {
            maxFreq = it.second; // contains the seond maximum frequency
            ans = it.first;  // contains the string having second maximum frequency
        }
    }
    return ans;
}

int main() {
    string arr[6] = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    cout<<"he second most repeated (or frequent) string in the given sequence is: "<<endl;
    cout<<secFrequent(arr, 6);
    return 0;
}