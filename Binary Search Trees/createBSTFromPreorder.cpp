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

node* solve(vector<int> &preorder, int mini, int maxi, int &i) {
    // if index is outside of array size 
    if(i >= preorder.size())
        return NULL;
        
    // if element doesn't lie between int_min and int_max range
    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;
        
    // if both cases are false then create node
    node* root = new node(preorder[i++]);
    
    // Since all elements in the left subtree of a BST must be less
    // than the root node's value, set range as `[min, root -> data]` and recur
    root -> left = solve(preorder, mini, root -> data, i);
    
    // Since all elements in the right subtree of a BST must be greater
    // than the root node's value, set range as `[root -> data, …max]` and recur
    root -> right = solve(preorder, root -> data, maxi, i);
    
    return root;
}

node* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    
    int i = 0;
    return solve(preorder, mini, maxi, i);
}

void inorder(node* root) {
    // base case
    if(root == NULL)
        return ;
        
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

int main() {
    
    /* Construct the following BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
    
    
    node* root = NULL;
    vector<int> preorder = {15, 10, 8, 12, 20, 16, 25};
    
    root = preorderToBST(preorder);
    
    cout<<"Traversal of bst is: "<<endl;
    inorder(root);
    
    return 0;
}