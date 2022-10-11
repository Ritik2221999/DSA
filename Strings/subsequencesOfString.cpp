#include<bits/stdc++.h>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans) {
    // base case
    if(index >= str.length()) {
        if(output.length() > 0) {
            ans.push_back(output);
        }
        return ;
    }
    
    // exclude elements -> just increment the elements
    solve(str, output, index+1, ans);
    
    // include elements
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str) {
    string output = "";
    int index = 0;
    vector<string> ans;
    
    solve(str, output, index, ans);
    return ans;
}

int main() {
    string str = "abc";
    
    vector<string> result;
    
    result = subsequences(str);
    
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<", ";
    }
    
    return 0;
}