#include<bits/stdc++.h>
using namespace std;

int findMaxLen(string str) {
    int n = str.length();
    
    stack<int> s;
    s.push(-1);
    
    int res = 0;
    
    for(int i=0; i<n; i++) {
        if(str[i] == '(')
            s.push(i);
        else {
            if(!s.empty()) {
                s.pop();
            }
            if(!s.empty()) {
                res = max(res, i - s.top());
            }
            else {
                s.push(i);
            }
        }
    }
    
    return res;
}

int main() {
    
    string str = "((()()";
    
    cout<<findMaxLen(str)<<endl;
    
    str = "()(()))))";
    cout<<findMaxLen(str)<<endl;
    
    
    return 0;
}