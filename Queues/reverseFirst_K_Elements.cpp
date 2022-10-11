#include<bits/stdc++.h>
using namespace std;

// using stack
// Time Complexity -> O(n)
// Space COmplexity -> O(n)
queue<int> modifyQueue(queue<int> q, int k)
 {
    // step: 1) pop first k from Queue and put into stack
    stack<int> s;
    
    for(int i=0; i<k; i++){
        int elem = q.front();
        q.pop();
        s.push(elem);
    }
    
    // step: 2) fetch from stack and push into queue
    while(!s.empty()) {
        int elem = s.top();
        s.pop();
        q.push(elem);
    }
    
    // step: 3) fetch first (n-k) element from queue and push_back
    int t = q.size() - k;
    
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
 }

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}

int main() {
    
    queue<int> q;
    int k = 3;
    
    for(int i=1; i<=5; i++) {
        q.push(i);
    }
    cout<<"before reversing first k: "<<k<<" elements "<<endl;
    printQueue(q);
    
    q = modifyQueue(q, k);
    
    cout<<"After revesing first k: "<<k<<" elements "<<endl;
    printQueue(q);
    
    return 0;
}