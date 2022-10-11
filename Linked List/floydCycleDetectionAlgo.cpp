#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

void insertAtEnd(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }cout<<"NULL\n";
}

void makeLoop(Node* &head, int position) {
    if(position == 0) return; 
    
    Node* temp = head;
    int count = 1;
    
    while(count < position) {
        temp = temp -> next;
        count++;
    }
    
    Node* loopNode = temp;
    
    while(temp->next != NULL) {
        temp = temp -> next;
    }
    temp -> next = loopNode;
}

Node* floydDetectioAlgo(Node* &head) {
    if(head == NULL || head -> next == NULL) {
        return NULL;
    }
    
    Node* fast = head;
    Node* slow = head;
    
    while(slow != NULL && fast != NULL) {
        fast = fast -> next;
        
        if(fast != NULL) {
            fast = fast -> next;    
        }
        slow = slow -> next;
        
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

int main() {
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;
    
    cout<<"Inserting at end: "<<endl;
    print(head);
    
    insertAtEnd(tail, 12);
    insertAtEnd(tail, 13);
    insertAtEnd(tail, 15);
    print(head);
    
    int pos;
    cout<<"Enter the position to connect to loop: "<<endl;
    cin>> pos;
    makeLoop(head, pos);
    
    if(floydDetectionAlgo(head)) {
        cout<<"Loop is present in linked list: "<<endl;
    }
    else {
        cout<<"Loop is not present in linked list: "<<endl;
    }
    
    return 0;
}