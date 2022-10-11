// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
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


node* inPre(node* root) {
    node* p = root -> left;
    
    while(p -> right)
        p = p -> right;
    return p;
}

node* inSuc(node* root) {
    node* p = root -> right;
    
    while(p -> left)
        p = p -> left;
    return p;
}

void findPreSuc(node* root, node*& pre, node*& suc, int key)
{

// Your code goes here
    if(!root) return ;
    
    if(root -> data == key) {
        if(root -> left)
            pre = inPre(root);
            
        if(root -> right)
            suc = inSuc(root);
            
        return ;
    }
    
    if(key > root -> data) {
        pre = root;
        findPreSuc(root -> right, pre, suc, key);
    }
    else if(key < root -> data) {
        suc = root;
        findPreSuc(root -> left, pre, suc, key);
    }
}

void inorder(node* root) {
    // base case
    if(root == NULL)
        return ;
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

int main() {
    
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    
    
    node* root = NULL;
    cout<<"Enter elements into BST: "<<endl;
    takeInput(root);
    
    int key = 65;
    
    node* pre = NULL, *suc = NULL;
    
    cout<<"Inorder is: "<<endl;
    inorder(root);
    cout<<endl;
 
    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor"<<endl;
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor"<<endl;
    
    return 0;
}