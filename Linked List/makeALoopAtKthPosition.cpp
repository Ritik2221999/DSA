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

void print(Node* &head, int total_Nodes) {
    Node* temp = head;
    int count = 0;
    
    while(count < total_Nodes) {
        count++;
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }cout<<endl;
}


int main() {
    Node* node1 = new Node(3);
    
    
    Node* head = node1;
    Node* tail = node1;
    
    cout<<"inserting At End: "<<endl;
    
    insertAtEnd(tail, 1);
    insertAtEnd(tail, 8);
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 4);
    print(head, 5);
    
    cout<<"Enter the position to connect the loop: "<<endl;
    int k;
    cin>>k;
    
    makeLoop(head, k);
    
    cout<<"modified list: "<<endl;
    print(head, 6);
    
}