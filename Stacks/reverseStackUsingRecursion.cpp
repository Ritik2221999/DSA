#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int num) {
    // base case
    if(s.empty()) {
        s.push(num);
        return ;
    }
    
    int ele = s.top();
    s.pop();
    
    insertAtBottom(s, num);
    s.push(ele);
}

void reverse(stack<int> s) {
    // base case
    if(s.empty())
        return ;
    int num = s.top();
    s.pop();
    
    reverse(s);
    insertAtBottom(s, num);
}

int main() {
    stack<int> s;
    
    cout<<"original stack is: "<<endl;
    for(int i=1; i<=5; i++) {
        cout<<i<<" ";
        s.push(i);
    }
    
    cout<<endl;
    
    reverse(s);
    
    cout<<"reversed stack is: "<<endl;
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}