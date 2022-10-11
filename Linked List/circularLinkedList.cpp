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
        
        ~Node() {
            int val = this -> data;
            
            if(this -> next != NULL) {
                delete next;
                next = NULL;
            }
            cout<<"memory is free for node with data: "<<val<<endl;
        }
};

void insertNode(Node* &tail, int element, int data) {
    // empty list
    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else {
        // non empty list 
        Node* curr = tail;
        
        while(curr -> data != element) {
            curr = curr -> next;
        }
        
        // insert at end when there are two or more than 2 nodes
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

Node* addToEmpty(Node* &tail, int data) {
    if(tail != NULL)
        return tail;
        
    Node* temp = new Node(data);
    tail = temp;
    temp -> next = temp;
    
    return temp;
}

Node* addToBegin(Node* &tail, int data) {
    
    if(tail == NULL)
        return addToEmpty(tail, data);
        
    Node* temp = new Node(data);
    temp -> next = tail -> next;
    tail -> next = temp;
    
    return tail;
}

Node* addToEnd(Node* &tail, int data) {
    if(tail == NULL) {
        return addToEnd(tail, data);
    }
    
    Node* temp = new Node(data);
    temp -> next = tail -> next;
    tail -> next = temp;
    tail = temp;
    
    return tail;
    
}

Node* addAtPosition(Node* &tail, int data, int item) {
    if(tail == NULL)
        return NULL;
        
    Node* temp, *curr;
    curr = tail -> next;
    
    do {
        if(curr -> data == item) {
            temp = new Node(data);
            temp -> next = curr -> next;
            curr -> next = temp;
            
            // checking for last node 
            if(curr == tail)
                tail = temp;
                
            return tail;
        }
        curr = curr -> next;
    } while(curr != tail -> next);
    
    cout<< item<<" not present in the list: "<<endl;
    return tail;
}

void printList(Node* &tail ) {
    Node* curr;
    
    if(tail == NULL) {
        cout<<"List is empty: "<<endl;
        return ;
    }
    // Pointing to first Node of the list. 
    curr = tail -> next;
    
    do {
        cout<<curr -> data<<" ";
        curr = curr -> next;
    } while(curr != tail -> next);
 cout<<endl;   
}

void deletion(Node* &tail, int value) {
    // empty list
    if(tail == NULL) {
        cout<<"List is empty: "<<endl;
        return ;
    }
    else {
        // non empty List
        Node* prev = tail;
        Node* curr = tail -> next;
        
        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }
        
        prev -> next = curr -> next;
        
        // deletion if single element is present in List
        if(curr == prev)
            tail = NULL;
    
        // deletion if 2 or more than 2 elements are present
        if(tail == curr) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main() {
    Node* tail = NULL;
    
    cout<<"insertion: "<<endl;
    tail = addToEmpty(tail, 6);
    tail = addToBegin(tail, 2);
    tail = addToEnd(tail, 9);
    tail = addAtPosition(tail, 10, 6);
    printList(tail);
    deletion(tail, 2);
    printList(tail);
    return 0;
}