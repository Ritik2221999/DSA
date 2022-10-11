// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void makeLoop(Node* &head, int position) {
    if(position == 0) return; 
    
    Node* temp = head;
    int count = 1;
    
    while(count < position) {
        temp = temp -> next;
        count++;
    }
    
    Node* loopNode = temp;
    
    while(temp->next != NULL) {
        temp = temp -> next;
    }
    temp -> next = loopNode;
}


bool detectLoop(Node* head)
{
    // your code here
    if(head == NULL)
        return false;
    
    map<Node*, bool> visited;
    Node* temp = head;
    
    while(temp != NULL) {
        // cycle is present
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

int main()
{
    int t;
    cout<<"Enter the testcase: "<<endl;
    cin>>t;
    cout<<"Enter the number of elements: "<<endl;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cout<<"Enter the position to connect to loop: "<<endl;
        cin>> pos;
        makeLoop(head, pos);
        
        if(detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}