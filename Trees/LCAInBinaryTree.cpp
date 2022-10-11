// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
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

node* buildTree(node* root) {
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    
    root = new node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter data inserting at left of: "<<data<<endl;
    root -> left = buildTree(root -> left);
    
    cout<<"Enter data inserting at right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

node* lca(node* root, int n1, int n2) {
    // base case
    if(root == NULL)
        return NULL;
        
    if(root -> data == n1 || root -> data == n2)
        return root;
        
    node* leftAns = lca(root -> left, n1, n2);
    node* rightAns = lca(root -> right, n1, n2);
    
    if(leftAns != NULL && rightAns != NULL)
        return root;
        
    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;
    
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
        
    else
        return NULL;
}

int main() {
    
    //        5    
    //       /    
    //      2  
    //     / \  
    //   3   4
    
    node* root = buildTree(root);
    int n1 = 3, n2 = 4;
    
    cout<<"\nLca of current binary tree is: "<<endl;
    cout<<lca(root, n1, n2) -> data <<endl;
    
    return 0;
}