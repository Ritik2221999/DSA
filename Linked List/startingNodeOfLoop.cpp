#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

Node* getStartingNodeofLoop(Node* &head) {
   if(head == NULL || head -> next == NULL) {
       return NULL;
   }
   
   Node* fast = head;
   Node* slow = head;
   
   while(slow != NULL && fast != NULL) {
       fast = fast -> next;
       if(fast != NULL) {
           fast = fast -> next;
       }
       slow = slow -> next;
       
       if(slow == fast)
            break;
   }
   
   if(slow != fast)
        return NULL;
        
    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

int main() {
    Node* head = newNode(1);
    head -> next = newNode(0);
    head -> next -> next = newNode(3);
    head -> next -> next -> next = newNode(0);
    head -> next -> next -> next -> next = newNode(1);
    
    head -> next -> next -> next -> next -> next = head -> next -> next;
    
    Node* loop = getStartingNodeofLoop(head);
    if(loop == NULL) {
        cout<<"loop does not exist: "<<endl;
    }
    else
        cout<<"loop starting node is: "<<loop -> data<<endl;
    
    return 0;
}