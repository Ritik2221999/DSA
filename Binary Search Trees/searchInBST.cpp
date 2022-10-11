#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
        
        node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* insertIntoBST(node* root, int data) {
    // base case
    if(root == NULL) {
        root = new node(data);
        return root;
    }
    
    if(data > root -> data) {
        // move to right
        root -> right = insertIntoBST(root -> right, data);
    }
    else {
        // move to left
        root -> left = insertIntoBST(root -> left, data);
    }
    return root;
}

void takeInput(node* &root) {
    int data;
    cin>>data;
    
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}


node* levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL) { // pevious levelof tree has been completely traversed
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout<<temp -> data<<" ";
            if(temp -> left != NULL) {
                q.push(temp -> left);
            }
            if(temp -> right != NULL) {
                q.push(temp -> right);
            }
        }
    }
}

void inorder(node* root) {
    if(!root)
        return ;
        
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

// searching
bool search(node* root, int val) {
    
    if(root == NULL)
        return false;
        
    if(root -> data == val) return true;
    
    // val is greater than root data
    if(root -> data < val)
        return search(root -> right, val);
    else if(root -> data > val)
        return search(root -> left, val);
    return false;
}

int main() {
    node* root = NULL;
    cout<<"Inserting at BST: "<<endl;
    
    takeInput(root);
    
    cout<<"inserted Values in BST are: (level order traversal) "<<endl;
    levelOrderTraversal(root);
    
    cout<<"\nInorder traversal: "<<endl;
    inorder(root);
    
    cout<<"\nSearching the element into BST: "<<endl;
    if(search(root, 6)) {
        cout<<" -> -> Element is present: <- <- "<<endl;
    }
    else {
        cout<<" -> -> Element is not present:  <- <- "<<endl;
    }
    return 0;
}