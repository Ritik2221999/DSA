#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackest(string &s) {
    stack<char> st;
    
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            // if "ch" is closing bracket or lower chracter
            if(ch == ')') {
                bool isRedundant = true;
                
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true)
                    return true;
                st.pop(); // popping openening brackets
            }
        }
    }
    return false;
}

int main() {
    
    string str = "((a+b))";
    
    if(findRedundantBrackest(str)) {
        cout<<"yes: "<<endl;
    }
    else {
        cout<<"no: "<<endl;
    }
    return 0;
}