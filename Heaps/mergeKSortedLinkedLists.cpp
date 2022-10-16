// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* next;
        
        node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

class compare {
    public:
        bool operator()(node* a, node* b) {
            return a -> data > b -> data;
        }
};

node* mergeKLists(node* arr[], int k) {
    priority_queue<node*, vector<node*>, compare> pq;
    
    for(int i=0; i<k; i++) {
        if(arr[i] != NULL)
            pq.push(arr[i]);
    }
    
    if(pq.empty())
        return NULL;
        
    node* dummy = new node(0);
    node* last = dummy;
    
    while(!pq.empty()) {
        node* curr = pq.top();
        pq.pop();
        
        // add the top element to resultant list 
        last -> next = curr;
        last = last -> next;
        
        // take the next node from the "same" list and insert it into the min-heap
        if(curr -> next != NULL) {
            pq.push(curr -> next);
        }
    }
    return dummy -> next;
}

void printList(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"nullptr";
}

int main() {
    int k = 3; // total number of linked lists 
    node* arr[k];
    
    arr[0] = new node(1);
    arr[0] -> next = new node(5);
    arr[0] -> next -> next = new node(7);
    cout<<"Elements in list 1: ";
    printList(arr[0]);
    
    arr[1] = new node(2);
    arr[1] -> next = new node(3);
    arr[1] -> next -> next = new node(6);
    arr[1] -> next -> next -> next = new node(9);
    cout<<"\nElements in list 2: ";
    printList(arr[1]);
    
    arr[2] = new node(4);
    arr[2] -> next = new node(8);
    arr[2] -> next -> next = new node(10);
    cout<<"\nElements in list 3: ";
    printList(arr[2]);
    
    cout<<"\n\nPrinting: "<<k<<" merged Linked lists: "<<endl;
    node* head = mergeKLists(arr, k);
    printList(head);
    
    return 0;
}