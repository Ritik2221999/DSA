// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
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


int getCount(Node *root, int l, int h)
{
  // your code goes here
    if(!root) return 0;
  
    if(root -> data >= l && root -> data <= h) {
        return 1 + getCount(root -> left, l, h) + getCount(root -> right, l, h);
    }
    else if(root -> data > h) {
        return getCount(root -> left, l, h);
    }
    else {
        return getCount(root -> right, l, h);
    }
}

int main() {
    
//       10
//      /  \
//     5    50
//   /    /  \
//   1    40  100
    
    Node* root = NULL;
    
    cout<<"Enter elements into BST: "<<endl;
    takeInput(root);
    
    int l = 5, h = 50;
    
    cout<<"Total BST nodes that lie between range "<<l <<" and "<<h<<" are "<<endl;
    cout<<getCount(root, l, h);
    
    return 0;
}