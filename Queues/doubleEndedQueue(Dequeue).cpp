#include<bits/stdc++.h>
using namespace std;

class Dequeue {
    int *arr;
    int size;
    int front;
    int rear;
    
public:
    Dequeue() {
        size = 1000001;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool pushFront(int x) {
        if(isFull())
            return false;
        else if (isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear != size - 1) {
            front = size - 1;
        }
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }
    
    bool pushRear(int x) {
        if(isFull())
            return false;
        else if(isEmpty()) {
            front = rear = 0;
        }
        else if(rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }
    
    int popFront() {
        if(isEmpty())
            return -1;
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) {
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; // maintain cyclic nature
        }
        else {
            front++;
        }
        return ans;
    }
    
    int popRear() {
        if(isEmpty()) {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear)
            front = rear = -1;
        else if(rear == 0)
            rear = size - 1;
        else
            rear--;
        return ans;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size - 1) || front != 0 && (rear == (front - 1))) {
            return true;
        }
        return false;
    }
};

int main() {
    Dequeue dq;
    
    cout << "Insert element at rear end  : 5 \n";
    dq.pushRear(5);
    
    cout << "insert element at rear end : 10 \n";
    dq.pushRear(10);
    
    cout << "get rear element " << " "
        << dq.getRear() << endl;
        
    dq.popRear();
    
    cout << "After delete rear element new rear"
        << " become " << dq.getRear() << endl;
         
    cout << "inserting element at front end \n";
    dq.pushFront(15);
    
    cout << "get front element " << " "
        << dq.getFront() << endl;
    
    dq.popFront();
    
    cout << "After delete front element new "
       << "front become " << dq.getFront() << endl;
    
    return 0;
}