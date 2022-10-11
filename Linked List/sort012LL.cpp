// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

class Solution
{
    public:
    // Approach -> 1
    Node* segregate(Node *head) {
        
        // Add code here
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        Node* temp = head;
        
        while(temp != NULL) {
            if(temp -> data == 0)
                zeroCount++;
            else if(temp -> data == 1)
                oneCount++;
            else if(temp -> data == 2)
                twoCount++;
                
            temp = temp -> next;
        }
        
        temp = head;
        
        while(temp != NULL) {
            if(zeroCount != 0) {
                temp -> data = 0;
                zeroCount--;
            }
            
            else if(oneCount != 0) {
                temp -> data = 1;
                oneCount--;
            }
            
            else if(twoCount != 0) {
                temp -> data = 2;
                twoCount--;
            }
            
            temp = temp -> next;
        }
        return head;
    }
};

void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }
    return 0;
}

// Approach -> 2 

/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
void insertAtTail(Node* &tail, Node* curr) {
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head)
{
//     dummy nodes -> if dont use, we have to use multiple if else
//     statements
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
//     create separate sub list of zero, one and two
    while(curr != NULL) {
        int value = curr -> data;
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr -> next;
    }
    
//     merge 3 sublist
    
//     1-s list is not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
//         1-s list is empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
//     setup head
    head = zeroHead -> next;
    
//     delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
    
}