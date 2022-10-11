// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1
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

void inorder(Node* root) {
    // base case
    if(!root)
        return ;
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}


void inorderTree(Node* root, vector<int> &v) {
    // base case
    if(root == NULL)
        return ;
        
    inorderTree(root -> left, v);
    v.push_back(root -> data);
    inorderTree(root -> right, v);
}

void inorderBst(Node* root, vector<int> v, int &i) {
    // base case
    if(root == NULL)
        return ;
        
    inorderBst(root -> left, v, i);
    root -> data = v[i];
    i++;
    inorderBst(root -> right, v, i);
}

Node *binaryTreeToBST (Node *root)
{
    //Your code goes here
    vector<int> v;
    inorderTree(root, v);
    
    sort(v.begin(), v.end());
    int i = 0;
    inorderBst(root, v, i);
    
    return root;
}

int main() {
    Node* root = NULL;
    
    cout<<"Enter elements into BST: "<<endl;
    takeInput(root);
    
    root = binaryTreeToBST(root);
    
    cout<<"Binary tree to BST is: "<<endl;
    inorder(root);
}