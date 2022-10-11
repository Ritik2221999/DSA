// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* buildTree(Node* root) {
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    
    root = new Node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter data inserting at left of: "<<data<<endl;
    root -> left = buildTree(root -> left);
    
    cout<<"Enter data inserting at right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

Node* solve(Node* root, int &k, int node) {
        // base case
        if(root == NULL)
            return NULL;
            
        if(root -> data == node) {
            return root;
        }
        
        Node* leftAns = solve(root -> left, k, node);
        Node* rightAns = solve(root -> right, k, node);
        
        if(leftAns != NULL && rightAns == NULL) {
            k--;
            if(k<=0) {
                // lock the node
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }
        
        if(leftAns == NULL && rightAns != NULL) {
            k--;
            if(k<=0) {
                // lock the node
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
        return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans -> data == node)  // node = root node
        return -1;
    else
        return ans -> data;
}

int main() {
    
    //        1    
    //       / \    
    //      2   3
    //     / \  
    //   4   5
    
    Node* root = buildTree(root);
    int kthAnc = 2, node = 4;
    
    cout<<"\nKth Ancestor of node "<<node<<" in binary tree: "<<endl;
    cout<<kthAncestor(root, kthAnc, node)<<endl;
    
    return 0;
}