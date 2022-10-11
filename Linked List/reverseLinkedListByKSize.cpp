#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{   
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


class Solution
{
public:
    struct node *reverse (struct node *head, int k)
    { 
        // base call
        if(head == NULL) {
            return NULL;
        }
        
        node* prev = NULL;
        node* curr = head;
        node* next = NULL;
        int count = 0;
        
        // step: 1) reverse for first k elements
        while(curr != NULL && count < k) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // step: 2) using recursion to reverse next k elements
        if(next != NULL) {
            head -> next = reverse(next, k);
        }
        
        return prev;
    }
};

int main(void)
{
    int t;
    cout<<"Enter the testcase: "<<endl;
    cin>>t;
 
while(t--)
{
    struct node* head = NULL;
    struct node* temp = NULL;
    
    int n;
    cout<<"Enter number of elements in linked list: "<<endl;
    cin >> n;
     
     cout<<"Enter the values: "<<endl;
    for(int i=0 ; i<n ; i++)
    {
        int value;
        cin >> value;
        if(i == 0)
        {
            head = new node(value);
            temp = head;
        }
        else
        {
            temp->next = new node(value);
            temp = temp->next;
        }
}

    int k;
    cout<<"Enter the k to be reversed by how many elements: "<<endl;
    cin>>k;
    
    Solution ob;
    head = ob.reverse(head, k);
    cout<<"The reversed list by k groups is: "<<endl;
    printList(head);
}

return(0);
}
