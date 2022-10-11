// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
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

void reverseLevelOrder(node* root) {
    vector<int> ans;
    if(!root) return ;
    
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()) {
        node* temp = q.front();
        
        ans.push_back(temp -> data);
        
        if(temp -> right != NULL)
            q.push(temp -> right);
            
        if(temp -> left != NULL)
            q.push(temp -> left);
        q.pop();   
    }
    reverse(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

int main() {
    
    node* root = NULL;
    root = buildTree(root);
    
    cout<<"Reverse Level order traversal is: ";
    reverseLevelOrder(root);

    return 0;
}