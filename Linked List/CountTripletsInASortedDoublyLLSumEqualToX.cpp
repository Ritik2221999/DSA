// https://www.codingninjas.com/codestudio/problems/count-triplets-in-a-sorted-doubly-linked-list-whose-sum-is-equal-to-a-given-value-x_985286?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

void insertAtEnd(Node* &tail, Node* &head, int data) {
    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else {
        Node* newNode = new Node(data);
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}

void print(Node* head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout<<temp -> data << "->";
        temp = temp -> next;
    }
    cout<<"Null";
    cout<<endl;
}

int countPairs(Node* first, Node* second, int val) {
    int count = 0;
    
    while(first != NULL && second != NULL && first != second && second -> next != first) {
        
        // pair found
        if((first -> data + second -> data) == val) {
            count++;
            
            first = first -> next;
            second = second -> prev;
        }
        else if((first -> data + second -> data) > val)
            second = second -> prev;
        else
            first = first -> next;
    }
    return count;
}

int countTriplets(Node* &head, int x) {
    if(head == NULL)
        return 0;
        
    Node* curr, *first, *last;
    int count = 0;
    
    last = head;
    
    while(last -> next != NULL)
        last = last -> next;
        
    for(curr = head; curr != NULL; curr = curr -> next) {
        first = curr -> next;
        
        count += countPairs(first, last, x - curr -> data);
    }
    return count;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    cout<<"Insert At End: "<<endl;
    insertAtEnd(tail, head, 1);
    print(head);
    
    insertAtEnd(tail, head, 2);
    print(head);
    
    insertAtEnd(tail, head, 4);
    print(head);
    
    insertAtEnd(tail, head, 5);
    print(head);
    
    insertAtEnd(tail, head, 6);
    print(head);
    
    insertAtEnd(tail, head, 8);
    print(head);
    
    insertAtEnd(tail, head, 9);
    print(head);
    
    int x = 17;
    
    cout<<"count is: "<<countTriplets(head, x);
    return 0;
}