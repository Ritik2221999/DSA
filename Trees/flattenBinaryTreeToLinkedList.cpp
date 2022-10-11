// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
        
        node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* buildTree(node* root) {
    cout<<"Enter the data: "<<endl;
    int data;
    cin>> data;
    
    root = new node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter data for inserting at left of: "<<data<<endl;
    root -> left = buildTree(root -> left);
    
    cout<<"Enter data for inserting at right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

void flatten(node *root)
{
    //code here
    if(root == NULL)
        return ;
        
    node* curr , *pred;
    
    curr = root;
            
    while(curr != NULL) {
        if(curr -> left) {
            pred = curr -> left;
            
            while(pred -> right != NULL)
                pred = pred -> right;
                
            pred -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
        }
        curr = curr -> right;
    }
}

void inorder(node* root) {
    if(root == NULL)
        return;
        
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

int main() {
    
    //       1
    //     /   \
    //    2     5
    //   / \     \
    //  3   4     6
    
    node* root = buildTree(root);
    
    flatten(root);
    
    cout<<"\nFlattening the tree to linked list: "<<endl;
    inorder(root);
    
    return 0;
}