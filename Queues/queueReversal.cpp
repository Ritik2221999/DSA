#include<bits/stdc++.h>
using namespace std;

// using stack
// Time Complexity -> O(n)
// Space COmplexity -> O(n)
queue<int> rev(queue<int> q) {
    stack<int> s;
    
    while(!q.empty()) {
        int elem = q.front();
        q.pop();
        s.push(elem);
    }
    
    while(!s.empty()) {
        int elem = s.top();
        s.pop();
        q.push(elem);
    }
    return q;
}

// using recursion
void reverse(queue<int>& q) {
    if(q.empty())
        return ;
    
    int element = q.front();
    q.pop();
    
    // recursive calls
    reverse(q);
    
    // push the reversed element into queue again
    q.push(element);
}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}

int main() {
    
    queue<int> q;
    
    for(int i=0; i<=10; i++) {
        q.push(i);
    }
    cout<<"Queue before reversing: "<<endl;
    printQueue(q);
    
    // q = rev(q);
    
    reverse(q);
    
    cout<<"After revesing Queue: "<<endl;
    printQueue(q);
    
    return 0;
}