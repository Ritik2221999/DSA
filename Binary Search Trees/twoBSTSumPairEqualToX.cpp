// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
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


int c;

bool fetch(Node* root2, int k) {
    if(!root2) return false;
    
    if(k == root2 -> data) return true;
    
    bool x, y;
    
    x = false;
    y = false;
    
    if(k < root2 -> data)
        x = fetch(root2 -> left, k);
    else if(k > root2 -> data)
        y = fetch(root2 -> right, k);
    return x || y;
}

void solve(Node* root1, Node* root2, int k) {
    if(!root1) return ;
    
    solve(root1 -> left, root2, k);
    if(fetch(root2, k - root1 -> data)) c++;
    solve(root1 -> right, root2, k);
}

int countPairs(Node* root1, Node* root2, int x)
{
    c = 0;
    solve(root1, root2, x);
    return c;
}


int main() {
    
//     BST1:                                   
//        5
//      /   \
//     3     7
//   / \    / \
//  2   4  6   8


//      BST2:
//        10
//      /    \
//     6      15
//   / \    /  \
//  3   8  11   18
    
    Node* root1 = NULL;
    Node* root2 = NULL;
    
    cout<<"Enter elements in BST-1: "<<endl;
    takeInput(root1);
    
    cout<<"Enter elements in BST-2: "<<endl;
    takeInput(root2);
    
    int x = 16;
    
    cout<<"Total number of pairs whose sum is equal to: "<<x<<endl;
    cout<<countPairs(root1, root2, x);
    
    return 0;
}