// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
#include<bits/stdc++.h>
using namespace std;

int evalPostfix(string str) {
    stack<int> s;
    
    for(char c: str) {
        if(c >= '0' && c <= '9') {
            s.push(c - '0');
        }
        else {
            int x = s.top();
            s.pop();
            
            int y = s.top();
            s.pop();
            
            if(c == '+')
                s.push(y + x);
            else if(c == '-')
                s.push(y - x);
            else if(c == '/')
                s.push(y / x);
            else if(c == '*')
                s.push(y * x);
        }
    }
    return s.top();
}

int main() {
    
    string expres = "138*+";
    cout<<evalPostfix(expres);
    
    return 0;
}