#include<bits/stdc++.h>
using namespace std;

class Queue {
    int* arr;
    int size;
    int qfront;
    int rear;
    
public:
    Queue() {
        size = 1000001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    
    bool isEmpty() {
        if(qfront == rear)
            return true;
        return false;
    }
    
    void enqueue(int data) {
        if(rear == size)
            return ;
        arr[rear] = data;
        cout<<data<<" enqueued to queue: "<<endl;
        rear++;
    }
    
    int dequeue() {
        if(qfront == rear)
            return -1;
        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }
    
    int front() {
        if(qfront == rear)
            return -1;
        return arr[qfront];
    }
};

int main() {
    Queue q1;
    
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    
    cout<<q1.dequeue()<<" dequeued from queue: "<<endl;
    
    cout<<"front item is: "<<q1.front()<<endl;
    
    return 0;
}