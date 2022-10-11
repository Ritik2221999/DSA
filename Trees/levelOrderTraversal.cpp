// https://practice.geeksforgeeks.org/problems/level-order-traversal/1
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

vector<int> levelOrder(node* root)
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
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            v.push_back(temp -> data);
          
            if(temp -> left != NULL)
                q.push(temp -> left);
            if(temp -> right != NULL)
                q.push(temp -> right);
        }
    }
    return v;     
}

int main() {
    
    node* root = NULL;
    root = buildTree(root);
    
    cout<<"Level order traversal is: ";
    vector<int> res = levelOrder(root);
    
    for(auto i: res) cout<<i<<" ";

    return 0;
}