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

Node* removeDuplicate(Node* &head) {
    if(head == NULL) {
        return NULL;
    }
    
    Node* curr = head;
    
    while(curr != NULL) {
        // same continuous elements
        if(curr -> next != NULL && curr -> data == curr -> next -> data) {
            Node* nextNode = curr -> next -> next;
            
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            
            curr -> next = nextNode;
        }
        else {
            // not same continuous elements
            curr = curr -> next;
        }
    }
    return head;
}

void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }cout<<"NULL\n";
}

int main() {
    Node* node1 = new Node(2);
    
    Node* head = node1;
    Node* tail = node1;
    
    print(head);
    
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 3);
    insertAtEnd(tail, 4);
    print(head);
    
    cout<<"removing the dupilicate element from linked list: "<<endl;
    removeDuplicate(head);
    print(head);
    return 0;
}