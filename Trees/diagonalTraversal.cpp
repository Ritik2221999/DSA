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

vector<int> diagonal(node *root)
{
   // your code here
   vector<int> ans;
   queue<node*> q;
   
    if(!root)
        return ans;
    q.push(root);
    
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        while(temp) {
            if(temp -> left)
                q.push(temp -> left);
            ans.push_back(temp -> data);
            temp = temp -> right;
        }
    }
    return ans;
}

int main() {
    //      8
    //     / \
    //    3  10
    //   / \   \
    //  1   6   14
    //     / \  /
    //    4  7 13
    
    node* root = buildTree(root);
    
    vector<int> ans = diagonal(root);
    
    cout<<"Diagonal traversal of binary tree: "<<endl;
    for(int i=0;i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}