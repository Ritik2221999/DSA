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

void moveLastTofront(Node* &head) {
    if(head == NULL || head -> next == NULL)
        return;
        
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr -> next != NULL) {
        prev = curr;
        curr = curr -> next;
    }
    
    prev -> next = NULL;
    curr -> next = head;
    head = curr;
}

void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }cout<<"NULL\n";
}

int main() {
    Node* node1 = new Node(1);
    
    Node* head = node1;
    Node* tail = node1;
    
    print(head);
    
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 3);
    insertAtEnd(tail, 4);
    insertAtEnd(tail, 5);
    print(head);
    
    cout<<"Moving the last node to front: "<<endl;
    moveLastTofront(head);
    print(head);
    return 0;
}