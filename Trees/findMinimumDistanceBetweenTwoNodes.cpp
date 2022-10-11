// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
        
        node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* buildTree(node* root) {
    cout<<"Enter the data: "<<endl;
    int data;
    cin>> data;
    
    root = new node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter data for inserting at left of: "<<data<<endl;
    root -> left = buildTree(root -> left);
    
    cout<<"Enter data for inserting at right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

int findLevel(node* root, int val) {
    // base case
    if(!root) return 0;
        
    if(root -> data == val)
        return 1;
        
    int left = findLevel(root -> left, val);
    int right = findLevel(root -> right, val);
    
    if(!left && !right) return 0;
    else return left + right + 1;
}

node* findLCA(node* root, int a, int b) {
    // base case
    if(root == nullptr)
        return nullptr;
        
    if(root -> data == a || root -> data == b)
        return root;
        
    node* left = findLCA(root -> left, a, b);
    node* right = findLCA(root -> right, a, b);
    
    if(left && right)
        return root;
        
    else if(left)
        return left;
        
    else if(right)
        return right;
    else
        return NULL;
}


int findDist(node* root, int a, int b) {
    
    // lca stores the lowest common ancestor of a and b
    node* lca = nullptr;
    
    lca = findLCA(root, a, b);
    
    int x = findLevel(lca, a);
    int y = findLevel(lca, b);
    
    return x + y - 2;  // -2 because we are adding 1 in both x and y
}

int main() {
    
    //     1
    //   /  \
    //  2    3
     
    int a = 2, b = 3;

    node* root = buildTree(root);
    
    cout<<"\nFind Minimum distance between two nodes: "<<endl;
    cout<<findDist(root, a, b)<<endl;
    
    
    
    return 0;
}