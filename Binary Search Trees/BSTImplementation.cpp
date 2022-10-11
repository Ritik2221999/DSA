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

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL) {
            cout<<" "<<endl;
            
            if(!q.empty()) 
                q.push(NULL);
        }
        else {
            cout<<temp -> data<<" ";
            
            if(temp -> left)
                q.push(temp -> left);
                
            if(temp -> right)
                q.push(temp -> right);
        }
    }
}

node* insertIntoBST(node* root, int data) {
    // base case
    if(root == NULL) {
        root = new node(data);
        return root;
    }
    
    // check for bst condition
    if(data > root -> data) {
        // insert at right side of bst 
        root -> right = insertIntoBST(root -> right, data);
    }
    else {
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

// inorder successor
node* minVal(node* root) {
    node* temp = root;
    
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

node* maxVal(node* root) {
    node* temp = root;
    
    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp;
}

node* deleteFromBST(node* root, int val) {
    // base case
    if(root == NULL)
        return root;
        
    if(root -> data == val) {
        // 0 - child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }
        
        // 1 - child -> 2 cases
        
        // 1.) for left child
        if(root -> left != NULL && root -> right == NULL) {
            node* temp = root -> left;
            delete root;
            return temp;
        }
        
        // 2.) for right child
        if(root -> left == NULL && root -> right != NULL) {
            node* temp = root -> right;
            delete root;
            return temp;
        }
        
        // 2 - child
        if(root -> left != NULL && root -> right != NULL) {
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini); // delete the inorder successor
            return root;
        }
    }
    else if(root -> data > val) {
        // move to left part
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else {
        // move to right part
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
    return NULL;
}


int main() {
    
    node* root = NULL;
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    
    cout<<"Printing the BST: "<<endl;
    levelOrderTraversal(root);
    
    cout<<"\nMinimum value of BST is: "<<minVal(root) -> data<<endl;
    cout<<"Maximum value of BST is: "<<maxVal(root) -> data<<endl;
    
    root = deleteFromBST(root, 3);
    
    cout<<"\nAfter deletion: "<<endl;
    levelOrderTraversal(root);
    
    return 0;
}