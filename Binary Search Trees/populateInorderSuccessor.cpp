// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
        node* next;
        
        node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
            this -> next = NULL;
        }
};

node* insertIntoBST(node* root, int data) {
    // base case
    if(root == NULL) {
        root = new node(data);
        return root;
    }
    
    if(data > root -> data) {
        root -> right = insertIntoBST(root -> right, data);
    }
    else {
        root -> left = insertIntoBST(root -> left, data);
    }
    return root;
}

void takeInput(node* &root) {
    int data;
    cin>>data;
    
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

void solve(node* root, node* &prev) {
    // base case
    if(!root) return ;
    
    solve(root -> left, prev);
    
    if(prev != NULL) {
        prev -> next = root;
    }
    prev = root;
    
    solve(root -> right, prev);
}

void populateNext(node *root)
{
    //code here
    node* prev = NULL;
    solve(root, prev);
}

node* inorder(node* root) {
    // base case
    if(root -> left == NULL)
        return root;
    inorder(root -> left);
}

int main() {
    
    
    node* root = NULL;
    cout<<"Enter elements into BST:"<<endl;
    takeInput(root);
    
    populateNext(root);
    
    node* ptr = inorder(root);
    
    cout<<"\nPopulting Inorder Successor: "<<endl;
    while(ptr) {
        printf("%d->%d ", ptr -> data, ptr -> next ? ptr -> next -> data : -1);
        ptr = ptr -> next;
    }
    cout<<endl;
    
    return 0;
}