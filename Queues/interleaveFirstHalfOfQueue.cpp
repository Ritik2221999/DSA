// https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q) {
    queue<int> temp;
    int halfSize = q.size() / 2;
    
    for(int i=0; i<halfSize; i++) {
        temp.push(q.front());
        q.pop();
    }
    
    while(!temp.empty()) {
        q.push(temp.front());
        q.push(q.front());
        q.pop();
        temp.pop();
    }
}

int main() {
    queue<int> q;
    
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    
    interLeaveQueue(q);
    int length = q.size();
    
    cout<<"Interleaved first half of queue: "<<endl;
    for(int i=0; i<length; i++) {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    
    return 0;
}