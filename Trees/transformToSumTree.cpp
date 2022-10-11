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

void levelOrder(node* root)
{
  //Your code here
  vector<int> v;
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL) { // separator -> purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout<<temp -> data<<" ";
          
            if(temp -> left != NULL)
                q.push(temp -> left);
            if(temp -> right != NULL)
                q.push(temp -> right);
        }
    }
}

int solve(node* root) {
    if(!root) return 0;
    
    int leftSum = solve(root -> left);
    int rightSum = solve(root -> right);
    int val = root -> data;
    root -> data = leftSum + rightSum;
    return val + leftSum + rightSum;
}

void toSumTree(node *node)
{
    // Your code here
    solve(node);
}

int main() {
    
    //         10
    //       /   \
    //     -2     6
    //   /  \   /  \
    //  8    -4  7   5
    
    node* root = buildTree(root);
    
    toSumTree(root);
    
    cout<<"Sum tree is: "<<endl;
    levelOrder(root);
    
    return 0;
}