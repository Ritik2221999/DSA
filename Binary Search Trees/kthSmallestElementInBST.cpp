// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
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
    // base case
    if(root == NULL)
        return -1;
        
    // left
    int left = solve(root -> left, i, k);
    
    if(left != -1)
        return left;
        
    // Node
    i++;
    if(i == k)
        return root -> data;
        
    // right
    return solve(root -> right,i, k);
}

int KthSmallestElement(Node *root, int K) {
    // add code here.
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

    int k = 2;
    
    cout<<k<<" smallest element in BST is: "<<endl;
    cout<<KthSmallestElement(root, k);
}