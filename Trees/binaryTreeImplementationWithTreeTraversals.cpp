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
    cin>>data;
    
    root = new node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter the data for inserting at left of: "<<data<<endl;
    root -> left = buildTree(root -> left);
    
    cout<<"Enter the data for inserting at right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL) { // purana level complete traverse ho chuka hai // called separator
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

// tree traversal Algo's

void inorder(node* root) {
    // base case
    if(root == NULL)
        return ;
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

void preorder(node* root) {
    // base case
    if(root == NULL)
        return ;
    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root) {
    // base case
    if(root == NULL)
        return ;
    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}


int main() {
    node* root = NULL;
    root = buildTree(root);
    
    cout<<"\nLevel order traversal is: "<<endl;
    levelOrderTraversal(root);
    
    cout<<"\ninorder traversal of tree is: "<<endl;
    inorder(root);
    
    cout<<"\npreorder traversal of tree is: "<<endl;
    preorder(root);
    
    cout<<"\npostorder travrersal of tree is: "<<endl;
    postorder(root);
    return 0;
}