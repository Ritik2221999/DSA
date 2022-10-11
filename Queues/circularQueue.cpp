#include<bits/stdc++.h>
using namespace std;

class CircularQueue {
    int *arr;
    int size;
    int front;
    int rear;
    
public:
    CircularQueue() {
        size = 1000001;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    // Check if the queue is full
    bool isFull() {
        if (front == 0 && rear == size - 1) {
          return true;
        }
        if (front == rear + 1) {
          return true;
        }
        return false;
    }
    
    // Check if the queue is empty
    bool isEmpty() {
        if (front == -1)
          return true;
        else
          return false;
    }
    
    bool enqueue(int value) {
        // check if queue is full or not
        if((front == 0 && rear == size - 1) || (rear == (front - 1)))
            return false;
        else if(front == -1) {
            // insert first element in queue
            front = rear = 0;
        }
        else if(rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        cout<<"Inserted value is: "<<value<<endl;
        return true;
    }
    
    int dequeue() {
        if(front == -1)
            return -1;
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear)  {  // single element
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; // maintain circular nature
        }
        else {
            front++;
        }
        return ans;
    }
    
    void display() {
        int i;
        if(isEmpty()) {
            cout<<endl<<"Queue is Empty: "<<endl;
        }
        else {
            cout<<"Front -> "<<front<<endl;
            cout<<"Items -> ";
            for(int i=front; i != rear; i = (i+1)%size) {
                cout<<arr[i];
            }
            cout<<arr[i];
            cout<<endl;
            cout<<endl<<"Rear -> "<<rear<<endl;
        }
    }
};

int main() {
    
    CircularQueue q;
    
    q.dequeue(); // fails because front = -1
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.enqueue(6);
    
    q.display();
    
    int elem = q.dequeue();
    
    if (elem != -1)
        cout << endl << "Deleted Element is " << elem<<endl;
    
    q.display();
    
    q.enqueue(7);
    
    q.display();
    
      // Fails to enqueue because front == rear + 1
    q.enqueue(8);
    
    return 0;
}