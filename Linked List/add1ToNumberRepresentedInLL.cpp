#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        // contructor
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

Node* reverse(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addUtil(Node* &head) {
    Node* res = head;
    Node *temp = NULL;
    int carry = 1;
    int sum = 0;
    
    while(head != NULL) {
        sum = carry + head -> data;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        head -> data = sum;
        temp = head;
        head = head -> next;
    }
    
    // if some carry is still there, add a new node to 
    // result list.
    if(carry > 0) {
        temp -> next = new Node( carry);
    }
    return res;  // return the head of the resultant list
}

// brute force approach
Node* addOne(Node* head) {
    head = reverse(head);
    head = addUtil(head);
    return reverse(head);
}

void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout << temp -> data<<"->";
        temp = temp -> next;
    }cout<<"NULL\n";
}

int main() {
    Node* node1 = new Node(4);
    
    Node* head = node1;
    Node* tail = node1;
    
    cout<<"Inserting at end: "<<endl;
    insertAtEnd(tail, 5);
    insertAtEnd(tail, 6);
    print(head);
    
    head = addOne(head);
    cout<<"resultant list is: "<<endl;
    
    print(head);
    
    return 0;
}