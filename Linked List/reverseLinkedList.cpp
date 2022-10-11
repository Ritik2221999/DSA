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

// reversing the linked list iterative
// Time Complexity -> O(n)
// Space Complexity -> O(1)
Node* reverseIterative(Node* &head) {
    if(head == NULL || head -> next == NULL) 
        return head;
        
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// reversing te linked list recursive
Node* reverseRecursive(Node* &head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    
    Node* chotaHead = reverseRecursive(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    
    return chotaHead;
}


void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }cout<<endl;
}

int main() {
    Node* node1 = new Node(10);
    
    
    Node* head = node1;
    Node* tail = node1;
    
    cout<<"inserting At End: "<<endl;
    print(head);
    
    insertAtEnd(tail, 12);
    print(head);
    
    insertAtEnd(tail, 13);
    print(head);
    
    insertAtEnd(tail, 14);
    print(head);
    
    cout<<"reversing the linked list iteratively: "<<endl;
    reverseIterative(head);
    print(tail);
    
    cout<<"reversing the linked list recursively: "<<endl;
    reverseRecursive(head);
    print(tail);
    
    return 0;
}