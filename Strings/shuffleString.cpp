#include<bits/stdc++.h>
using namespace std;

string restoreString(string s, vector<int> &indices) {
    string str = s;
    
    for(int i=0; i<s.length(); i++) {
        str[indices[i]] = s[i];
    }
    return str;
}

int main() {
    string s = "codeleet";
    vector<int> indices = {4,5,6,7,0,2,1,3};
    
    string result;
    result = restoreString(s, indices);
    
    cout<<result<<endl;
    return 0;
}