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

void solve(node* root, vector<int> &ans, int level) {
    // base case
    if(root == NULL)
        return ;
    
    // we entered to new level
    if(level == ans.size())
        ans.push_back(root -> data);
        
    solve(root -> left, ans, level+1);
    solve(root -> right, ans, level+1);
}

vector<int> leftView(node* root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}


int main() {
    node* root = NULL;
    
    root = buildTree(root);
    vector<int> res = leftView(root);
    
    cout<<"left view of binary tree is: "<<endl;
    for(auto i: res) cout<<i<<" ";
    cout<<endl;
    return 0;
}