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

class compare {
    public:
        bool operator()(Node* first, Node* second) {
            return first -> data > second -> data;
        }
};

Node* sort(Node* head, int k) {
    if(head == NULL)
        return head;
        
    priority_queue<Node*, vector<Node*>, compare> pq;
    
    Node* newHead = NULL, *curr;
    
    for(int i=0; head != NULL && i<=k; i++) {
        pq.push(head);
        head = head -> next;
    }
    
    while(!pq.empty()) {
        if(newHead == NULL) {
            newHead = pq.top();
            newHead -> prev = NULL;
            curr = newHead;
        }
        else {
            curr -> next = pq.top();
            pq.top() -> prev = curr;
            curr = pq.top();
        }
        
        pq.pop();
        
        if(head != NULL) {
            pq.push(head);
            head = head -> next;
        }
    }
    curr -> next = NULL;
    
    return newHead;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    cout<<"Insert At End: "<<endl;
    insertAtEnd(tail, head, 3);
    print(head);
    
    insertAtEnd(tail, head, 6);
    print(head);
    
    insertAtEnd(tail, head, 2);
    print(head);
    
    insertAtEnd(tail, head, 12);
    print(head);
    
    insertAtEnd(tail, head, 56);
    print(head);
    
    insertAtEnd(tail, head, 8);
    print(head);
    
    int k = 2;
    
    cout<<"\nSorted a k Doubly ll: "<<endl;
    Node* temp = sort(head, k);
    print(temp);
    return 0;
}