// https://practice.geeksforgeeks.org/problems/check-for-bst/1
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

bool validateBST(node* root, int min, int max) {
    // base case
    if(root == NULL)
        return true;
    
    if(root -> data >= min && root -> data <= max) {
        bool left = validateBST(root -> left, min, root -> data);
        
        bool right = validateBST(root -> right, root -> data, max);
        
        return left && right;
    }
    return false;
}

bool isBST(node* root) 
{
    // Your code here
    return validateBST(root, INT_MIN, INT_MAX);
}

int main() {
    node * root = new node(7);
    root -> left = new node(5);
    root -> left -> left = new node(3);
    root -> left -> right = new node(6);
    root -> right = new node(10);
    root -> right -> left = new node(4);
    root -> right -> right = new node(15);

    bool ans = isBST(root);
    if (ans == true) {
        cout << "Valid BST";
    } else {
        cout << "Invalid BST";
    }
    
    return 0;
}