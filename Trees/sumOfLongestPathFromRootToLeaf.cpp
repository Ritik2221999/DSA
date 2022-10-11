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

void solve(node* root, int sum, int &maxSum, int len, int &maxLen) {
    // base case
    if(root == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } 
        else if(len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return ;
    }
    sum = sum + root -> data;
    
    solve(root -> left, sum, maxSum, len+1, maxLen);
    solve(root -> right, sum, maxSum, len+1, maxLen);

}


int sumOfLongRootToLeafPath(node *root)
{
    //code here
    int len = 0;
    int maxLen = 0;
    
    int sum = 0;
    int maxSum = INT_MIN;
    
    solve(root, sum, maxSum, len, maxLen);
    
    return maxSum;
}

int main() {
    
    //     4        
    //   / \       
    //  2   5      
//     / \ / \     
//    7  1 2  3    
//      /
//     6
    
    
    node* root = buildTree(root);
    
    cout<<"Maximum sum from root to leaf node is: "<<endl;
    cout<<sumOfLongRootToLeafPath(root);
    
    return 0;
}