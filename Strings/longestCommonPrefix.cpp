#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &str) {
    
    // base cases
    int strSize = str.size();
    
    if(strSize == 0)
        return "";
        
    else if(strSize == 1)
        return str[0];
    
        sort(str.begin(), str.end());
        int len = str[0].size();
        string result = "";
            
        for(int i=0; i<len; i++) {
            if(str[0][i] == str[strSize-1][i])
                result += str[0][i];
            else
                break;
        }
    return result;
}

int main() {
    vector<string> str = {"flower","flow","flight"};
    cout<<"The longest common prefix is: "<<endl;
    cout<<longestCommonPrefix(str);
    
    return 0;
}