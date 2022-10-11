// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1
#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;

class Stack {
    queue<int> q1, q2;
    
public:
    // insert an item into Stack
    void push(int data) {
        // move all elements from first to second queue
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // push the current data into first queue
        q1.push(data);
        
        // now again move all the elements in second queue to first queue
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    // remove an item from Stack
    int pop() {
        if(q1.empty()) {
            cout<<"\nUderflow: "<<endl;
            exit(0);
        }
        int front = q1.front();
        q1.pop();
        return front;
    }
};

int main() {
    vector<int> keys = {1, 2, 3, 4, 5};
    
    Stack s;
    for(int key: keys) {
        cout<<"inserting element: "<<key<<" into stack: "<<endl;
        s.push(key);
    }
    
    cout<<"popping elements from stack using two queues is: "<<endl;
    for(int i=0; i<=keys.size(); i++) {
        cout<<s.pop()<<" ";
    }cout<<endl;
    
    return 0;
}