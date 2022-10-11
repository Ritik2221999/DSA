#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next; //self referential pointer 
};

//Here, head is the head of the current linked list.
// We will store the heads of the 2 linked lists that
//we get on splitting in head1 and head2 respectively
void split(Node *head, Node **head1,Node **head2)
{
	Node *slow = head;
	Node *fast = head;
	
    //if the linked list is empty
    //we can't split it
	if(head == NULL)
		return;

    Node *tail = head;

    //finding the tail of the LL
    while(tail->next != head) {
        tail = tail->next;
    }
	
    //finding the middle of the LL
	while(fast->next != head && fast->next->next != head)
	{
        //move fast 2 steps at a time
		fast = fast->next->next;
        //move slow 1 step at a time
		slow = slow->next;
	}
	
	Node *middle = slow;

    //set head1 and head2 and split 
    //LL in 2 circular halves	
	*head1 = head;
	*head2 = middle->next;

    tail->next = *head2;	
	middle->next = *head1;
}

//Utility functions for creation and display of LL
void push(Node **head, int data)
{
	Node *ptr = new Node();
	Node *temp = *head;
	ptr->data = data;
	ptr->next = *head;

	if(*head != NULL)
	{
		while(temp->next != *head)
		temp = temp->next;	
		temp->next = ptr;
	}
	else
		ptr->next = ptr; 
	
	*head = ptr;
}

void displayCircularList(Node *head)
{
	Node *ptr = head;
	cout<<ptr->data<<" ";
	ptr = ptr->next;
    while(ptr != head) {
        cout<<ptr->data<<" ";
        ptr = ptr->next; 
    }

    cout<<"\n";
}

// Driver Code
int main()
{
	int n;

	/* Initialize lists as empty */
	Node *head = NULL;
	Node *head1 = NULL;
	Node *head2 = NULL;

    cin>>n; //number of elements in the LL
    
    for(int i=1;i<=n;i++) {
		int ele;
		cin>>ele;
		push(&head,ele);
	}

	cout << "Given Circular Linked List\n";
	displayCircularList(head);	
	
	//Splitting the List
	split(head, &head1, &head2);
	
    cout<<"After splitting\n";

	cout << "First Circular Linked List\n";
	displayCircularList(head1);
	
	cout << "Second Circular Linked List\n";
	displayCircularList(head2);
	return 0;
}