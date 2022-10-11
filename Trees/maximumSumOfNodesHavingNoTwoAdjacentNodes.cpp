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

unordered_map<node*, int> dp;

int maximumSumOfNodes(node* root) {
//     base case
    if(!root)
        return 0;
    
    if(dp[root])
        return dp[root];
    
    int incl = root -> data;
    if(root -> left) {
        incl += maximumSumOfNodes(root -> left -> left);
        incl += maximumSumOfNodes(root -> left -> right);
    }
    if(root -> right) {
        incl += maximumSumOfNodes(root -> right -> left);
        incl += maximumSumOfNodes(root -> right -> right);
    }
    int excl = maximumSumOfNodes(root -> left) + maximumSumOfNodes(root -> right);
    
    dp[root] = max(incl, excl);
    
    return dp[root];
    
}

int main() {
    
        //        1
        //      /  \
        //    2     3
        //   /     / \
        //  1     4   5
    
    
    node* root = buildTree(root);
    
    cout<<"\nMaximum sum of nodes having no two adjacent nodes: "<<endl;
    cout<<maximumSumOfNodes(root);
    
    return 0;
}