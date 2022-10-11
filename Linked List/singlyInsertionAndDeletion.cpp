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
        
        // destructor
        ~Node() {
            int value = this -> data;
            // memory free
            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }
            cout<<"memory is free for node with data: "<<value<<endl;
        }
};

// insert At beginning
void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

// insert At end
void insertAtEnd(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

// insert At Any Position
void insertAtGivenPosition(Node* &head, Node* &tail, int position, int data) {
    // insert At start
    if(position == 1) {
        insertAtHead(head, data);
        return ;
    }
    
    Node* temp = head;
    int cnt = 1;
    
    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
    }
    
    // insert At last position
    if(temp -> next == NULL) {
        insertAtEnd(head, data);
        return ;
    }
    
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

// delete the given Node
void deleteNode(int position, Node* &head) {
    // deleteing first or starting node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {
        // delete at any position or at end
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

// printing the LinkedList 
void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout << temp -> data<<" ";
        temp = temp -> next;
    }cout<<endl;
}

int main() {
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;
    
    cout<<"insertinng At beginning: "<<endl;
    print(head);
    
    insertAtHead(head, 15);
    print(head);
    
    insertAtHead(head, 22);
    print(head);
    
    cout<<"Inserting at end: "<<endl;
    insertAtEnd(tail, 29);
    print(head);
    
    cout<<"Inserting at given position: "<<endl;
    insertAtGivenPosition(head, tail, 1, 99);
    print(head);
    
    cout<<"deletting the node: "<<endl;
    deleteNode(1, head);
    print(head);
    
    return 0;
}