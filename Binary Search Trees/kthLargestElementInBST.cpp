// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    // base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }
    
    if(d > root -> data) {
        // insert at right subtree
        root -> right = insertIntoBST(root -> right, d);
    } else {
        // insert at left subtree
        root -> left = insertIntoBST(root -> left, d);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    
    cin>>data;
    
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

int solve(Node* root, int &i, int k) {
    // reverse inorder
    
    if(root == NULL)
        return -1;
        
    // right
    int right = solve(root -> right, i, k);
    
    if(right != -1)
        return right;
        
    // Node
    i++;
    if(i == k)
        return root -> data;
        
    // left
    return solve(root -> left, i, k);
}


int kthLargest(Node *root, int K)
{
    //Your code here
    int i = 0;
    return solve(root, i, K);
}

int main() {
    
//       5
//     /   \
//   2      7
    
    Node* root = NULL;
    
    cout<<"Enter elements into BST: "<<endl;
    takeInput(root);

    int k = 1;
    
    cout<<k<<" largest element in BST is: "<<endl;
    cout<<kthLargest(root, k);
}