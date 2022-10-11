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

void preorderTraversal(Node* root) {
    // base case
    if(root == NULL)
        return ;
    
    cout<<root -> data<<" ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

void inorder(Node* root, vector<int> &v) {
    // base case
    if(!root)
        return ;
    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);
}

Node* inorderToBST(int start, int end, vector<int> &inorderVal) {
    // base case
    if(start > end)
        return NULL;
        
    int mid = (start + end)/2;
    
    Node* root = new Node(inorderVal[mid]);
    
    root -> left = inorderToBST(start, mid-1, inorderVal);
    
    root -> right = inorderToBST(mid+1, end, inorderVal);
    
    return root;
}

Node* balancedBST(Node* root) {
    vector<int> inorderVal;
    
    inorder(root, inorderVal);
    
    return inorderToBST(0, inorderVal.size()-1, inorderVal);
}


int main() {
    
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
    
    Node* root = NULL;
    
    cout<<"Enter elements into BST: "<<endl;
    takeInput(root);
    
    root = balancedBST(root);
    
    cout<<"normal BST to balanced BST "<<endl;
    preorderTraversal(root);
}