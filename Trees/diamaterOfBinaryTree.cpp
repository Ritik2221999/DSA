// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
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


int height(node* root) {
    // base case
    if(root == NULL)
        return 1;
        
    int left = height(root -> left);
    int right = height(root -> right);
    
    int ans = max(left, right) + 1;
    return ans;
}

// Time Complexity -> O(n^2)
int diameter(node* root) {
    // base case
    if(root == NULL)
        return 1;
        
    int op1 = diameter(root -> left);
    int op2 = diameter(root -> right);
    
    int op3 = height(root -> left) + height(root -> right) + 1;
    
    int ans = max(op1, max(op2, op3));
    
    return ans;
}

// Appraoch-2
// Time Complexity -> O(n)

pair<int, int> diameterFast(node* root) {
    // base case
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    
    pair<int, int> left = diameterFast(root -> left);
    pair<int, int> right = diameterFast(root -> right);
    
    int op1 = left.first;
    int op2 = right.first;
    
    int op3 = (left.second) + (right.second) + 1;
    
    pair<int, int> ans;
    
    // for diamater
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    
    return ans;
}

int main() {
    
//           10
//         /   \
//       20    30
//     /   \ 
//   40   60
    
    node* root = buildTree(root);
    
    cout<<"\nDiameter of binary tree: "<<endl;
    
    cout<<height(root)<<endl;
    
    cout<<diameterFast(root).first<<endl;
    
    return 0;
}