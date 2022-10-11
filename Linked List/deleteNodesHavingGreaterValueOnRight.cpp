// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

class Solution
{
    public:
    
    Node* reverse(Node* root) {
        Node* prev = NULL;
        Node* curr = root;
        
        while(curr != NULL) {
            Node* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }    
    
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        Node* curr = head;
        
        int maxi = curr -> data;
        Node* prev = head;
        head = head -> next;
        
        while(head) {
            if(head -> data >= maxi) {
                maxi = head -> data;
                prev = head;
                head = head -> next;
            }
            else { // delete the curr element
                prev -> next = head -> next;
                head = prev -> next;
                
            }
        }
        head = reverse(curr);
        return head;
    }
    
};

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}