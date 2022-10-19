// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
#include<iostream>
#include<queue>
#include<vector>
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

int totalNodes(Node* tree) {
    if(tree == NULL)
        return 0;
    int ans = 1 + totalNodes(tree -> left) + totalNodes(tree -> right);
    return ans;
}

bool isCBT(Node* tree, int index, int count) {
    if(tree == NULL)
        return true;
    
    if(index >= count)
        return false;
    else {
        bool left = isCBT(tree -> left, 2 * index + 1, count);
        bool right = isCBT(tree -> right, 2 * index + 2, count);
        return (left && right);
    }
}

bool isMaxOrder(Node* tree) {
    // leaf nodes
    if(tree -> left == NULL && tree -> right == NULL)
        return true;
        
    // if only left exist
    if(tree -> right == NULL)
        return (tree -> data > tree -> left -> data);
    
    // if both child exist
    else {
        bool left = isMaxOrder(tree -> left);
        bool right = isMaxOrder(tree -> right);
        
        return (left && right && (tree -> data > tree -> left -> data &&
                                  tree -> data > tree -> right -> data)
                );
    }
}

bool isHeap(struct Node* tree) {
    // code here
    int currIndex = 0;
    int totalCount = totalNodes(tree);
    
    if(isCBT(tree, currIndex, totalCount) && isMaxOrder(tree)) {
        return true;
    }
    else  
        return false;
}

int main() {
    
    /* Construct the following tree
               2
             /   \
            /     \
           3       4
          / \     / \
         /   \   /   \
        5     6 8    10
    */
    
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(8);
    root->right->right = new Node(10);
    
    if(isHeap(root)) {
        cout<<"The given binary tree is a max-heap"<<endl;
    }
    else {
        cout<<"The given binary tree is a not a max-heap"<<endl;
    }
}