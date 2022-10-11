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

int solve(node* root, int  &ans) {
    if(root == NULL)
        return 0;
        
    int maxSum = root -> data;
    maxSum += solve(root -> left, ans) + solve(root -> right, ans);
    
    ans = max(ans, maxSum);
    
    return maxSum;
}

int findLargestSubtreeSum(node* root)
{
    //Write your code 
    if(root == NULL)
        return 0;
        
    int ans = INT_MIN;
    
    solve(root, ans);
    
    return ans;
}

int main() {
    
        //        1
        //      /   \
        //    2      3
        //   / \    / \
        //  4   5  6   7
    
    
    node* root = buildTree(root);
    
    cout<<"Largest Subtree sum is: "<<endl;
    cout<<findLargestSubtreeSum(root);
    
    return 0;
}