// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
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

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* even = NULL;
        Node* odd = NULL;
        Node* e = NULL;
        Node* o = NULL;
        
        while(head) {
            if(head -> data % 2 == 0) {
                if(even == NULL) {
                    even = head;
                    e = head;
                }
                else {
                    e -> next = head;
                    e = e -> next;
                }
            }
            else {
                if(odd == NULL) {
                    odd = head;
                    o = head;
                }
                else {
                    o -> next = head;
                    o = o -> next;
                }
            }
            head = head -> next;
        }
        if(e) e -> next = odd;
        if(o) o -> next = NULL;
        if(even) return even;
        return odd;
    }
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
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}