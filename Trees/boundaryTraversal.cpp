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

void traversalLeft(node* root, vector<int> &ans) {
    // base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        return ;
        
    ans.push_back(root -> data);
    
    if(root -> left != NULL)
        traversalLeft(root -> left, ans);
    else
        traversalLeft(root -> right, ans);
}

void traversalLeaf(node* root, vector<int> &ans) {
    // base case
    if(root == NULL)
        return ;
    
    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
        return ;
    }
    
    traversalLeaf(root -> left, ans);
    traversalLeaf(root -> right, ans);
        
}

void traversalRight(node* root, vector<int> &ans) {
    // base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        return ;
    
    if(root -> right != NULL)
        traversalRight(root -> right, ans);
    else
        traversalRight(root -> left, ans);
        
    // while returning from bottom to top print values or store
    ans.push_back(root -> data);
}

vector <int> boundary(node *root)
{
    //Your code here
    vector<int> ans;
    
    if(root == NULL)
        return ans;
        
    ans.push_back(root -> data);
    
    // print left part
    traversalLeft(root -> left, ans);
    
    // traversing leaf nodes
    
    // for left subtree
    traversalLeaf(root -> left, ans);
    
    // for right subtree
    traversalLeaf(root -> right, ans);
    
    // print right part from bottom to top except leaf and root node
    traversalRight(root -> right, ans);
    
    return ans;
}

int main() {
    
//         1 
//       /   \
//      2     3  
//     / \   / \ 
//   4   5  6   7
//      / \
//     8   9
    
    node* root = buildTree(root);
    
    vector<int> result = boundary(root);
    
    cout<<"boundary traversal of binary tree: "<<endl;
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    return 0;
}