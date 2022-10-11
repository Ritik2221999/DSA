// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getNthFromLast(struct Node* head, int n);

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}

int getNthFromLast(Node *head, int n)
{
       // Your code here
       
      Node* temp = head;
      int len = 0;
      
      while(temp != NULL) {
        temp = temp -> next;
        len++;
      }
      
      if(len >= n) {
          temp = head;
          
          for(int i=1; i<len-n+1; i++) {
              temp = temp -> next;
          }
      }
      else
        return -1;
      return temp -> data;
}