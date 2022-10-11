#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int data) {
            this -> data = data;
            this -> next =  NULL;
        }
};

void insertAtEnd(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev =  NULL;
    Node* next =  NULL;
    
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* &head) {
    if(head == NULL || head -> next == NULL)
        return true;
        
    // step: 1) find middle
    Node* middle = getMid(head);
    
    // step: 2) reverse list after getting middle
    Node* temp = middle -> next;
    middle -> next = reverse(temp);
    
    // step: 3) compare both halves;
    Node* head1 = head;
    Node* head2 = middle -> next;
    
    while(head2 != NULL) {
        if(head1 -> data != head2 -> data)
            return false;
        
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    // step:4) repeat step 2 
    temp = middle -> next;
    middle -> next = reverse(temp);
    
    return true;
}

void printList(Node* head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }cout<<endl;
}

int main() {
    Node* node1 = new Node(1);
    
    Node* head = node1;
    Node* tail = node1;
    
    cout<<"insert at end: "<<endl;
    printList(head);
    
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 1);
    insertAtEnd(tail, 4);
    
    printList(head);
    
    if(isPalindrome(head)) {
        cout<<"current list is in palidrome: "<<endl;
    }
    else {
        cout<<"current list is not in palindrome: "<<endl;
    }
    return 0;
}