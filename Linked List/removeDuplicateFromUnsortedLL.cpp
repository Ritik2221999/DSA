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

Node* removeDuplicates( Node *head) 
{
 // your code goes here
    if(head == NULL) {
        return NULL;
    }
    
    unordered_set<int> st;
 
    Node* curr = head;
    Node* prev = NULL;
     
    while(curr != NULL) {
        if(st.find(curr -> data) != st.end()) {
            prev -> next = curr -> next;
            delete(curr);
        }
        else {
            st.insert(curr -> data);
            prev = curr;
        }
        curr = prev -> next;
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
    
    insertAtEnd(tail, 3);
    insertAtEnd(tail, 4);
    insertAtEnd(tail, 2);
    print(head);
    
    cout<<"removing the dupilicate element from unsorted linked list: "<<endl;
    removeDuplicates(head);
    print(head);
    return 0;
}