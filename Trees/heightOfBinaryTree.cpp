// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
};

node* newNode(int data) {
    node* temp = new node();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}

int height(node* root) {
    if(root == NULL)
        // return -1;
        return 0;
        
    int left = height(root -> left);
    int right = height(root -> right);
    
    int maxHeight = max(left, right) + 1;
    
    return maxHeight;
}

int main() {
    
    node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    
    cout<<"height of tree is: "<<height(root);
    
    return 0;
}