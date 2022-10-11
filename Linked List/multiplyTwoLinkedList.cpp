#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
}node;

node* createNode(int data, node* start) {
    node* p = new node();
    
    p -> data = data;
    p -> next = NULL;
    
    node* temp = start;
    
    if(start == NULL) {
        start = p;
        start -> next = NULL;
    }
    else {
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = p;
    }
    return start;
}

void printList(node* s) {
    node* p = s;
    while(p != NULL) {
        cout<<p -> data;
        if(p -> next != NULL)cout<<"->";
        p = p -> next;
    }
}

int multiply(node* head1, node* head2) {
    Node* p = head1;
    long long int x = 0, y = 0;
    long long mod = 1000000007;
    while(p != NULL) {
        x = ((x * 10) + p -> data) % mod;
        p = p -> next;
    }
    
    p = head2;
    
    while(p != NULL) {
        y = ((y * 10) + p -> data) % mod;
        p = p -> next;
    }
    return (x * y) % mod;
}

int main() {
    node* head1 = NULL;
    head1 = createNode(2, head1);
    head1 = createNode(1, head1);
    head1 = createNode(5, head1);
    
    node* head2 = NULL;
    head2 = createNode(1, head2);
    head2 = createNode(2, head2);
    
    cout<<"Linked list 1: "<<endl;
    printList(head1);
    
    cout<<"Linked list 2: "<<endl;
    printList(head2);
    
    int ans = multiply(head1, head2);
    cout<<"\nMultiplication is: "<<ans;
    
    return 0;
}
