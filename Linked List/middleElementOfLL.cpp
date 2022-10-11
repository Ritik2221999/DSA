// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

// Brute force Appraoch
int getLength(Node* head) {
    int len = 0;
    
    while(head != NULL) {
        len++;
        head = head -> next;
    }
    return len;
}

int getMiddle(Node* head) {
    int len = getLength(head);
    int ans = len / 2;
    
    Node* temp = head;
    int cnt = 0;
    
    while(cnt < ans) {
        ans++;
        temp = temp -> next;
    }
    return temp;
}

// optimized Approach
int getMiddle(Node *head)
{
    // Your code here
    if(head == NULL)
        return -1;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow -> data;
}

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        cout<<getMiddle(head) << endl;
    }
    return 0;
}