// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
        
        node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* insertIntoBST(node* root, int data) {
    // base case
    if(root == NULL) {
        root = new node(data);
        return root;
    }
    
    // check for bst condition
    if(data > root -> data) {
        // insert at right side of bst 
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

// recursive Approach
node* LCA(node *root, int n1, int n2)
{
   //Your code here
   if(root == NULL)
        return NULL;
    
    if(root -> data < n1 && root -> data < n2)
        return LCA(root -> right, n1, n2);
    
    if(root -> data > n1 && root -> data > n2)
        return LCA(root -> left, n1, n2);
        
    return root;
}

// iterative Approach
node* lca(node* root, int n1, int n2) {
    // base case
    if(root == NULL)
        return NULL;
        
    while(root != NULL) {
        if(root -> data < n1 && root -> data < n2)
            root = root -> right;
            
        else if(root -> data < n1 && root -> data < n2)
            root = root -> left;
        else
            return root;
    }
}


int main() {
    
    //          5
    //       /    \
    //      4      6
    //     /        \
    //   3           7
    //                \
    //                 8
    
    
    node* root = NULL;
    cout<<"Enter elements in BST: "<<endl;
    takeInput(root);
    
    int n1 = 7;
    int n2 = 8;
    
    cout<<"Lca of: "<<n1<<" and "<<n2<<" is: "<<endl;
    cout<<lca(root, n1, n2) -> data;
    
    return 0;
}