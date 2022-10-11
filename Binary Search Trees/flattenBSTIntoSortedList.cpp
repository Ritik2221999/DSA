#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    // base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    
    if(data > root -> data) {
        // insert into right side
        root -> right = insertIntoBST(root -> right, data);
    }
    else {
        root -> left = insertIntoBST(root -> left, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin>>data;
    
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}


void inorder(Node*  root, vector<int> &in) {
    // base case
    if(root == NULL)
        return ;
        
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

Node* flatten(Node* root) {
    vector<int> inorderVal;
    
    // step: 1) store inorder sorted values
    inorder(root, inorderVal);
    int n = inorderVal.size();
    
    Node* newRoot = new Node( inorderVal[0]);
    
    Node* curr = newRoot;
    
    // step: 2)
    for(int i=1; i<n; i++) {
        Node* temp = new Node(inorderVal[i]);
        
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }
    
    // step: 3)
    curr -> left = NULL;
    curr -> right = NULL;
    
    return newRoot;
}

void print(Node* parent) {
    Node* curr = parent;
    
    while(curr != NULL) {
        cout<<curr -> data<<" ";
        curr = curr -> right;
    }
    cout<<endl;
}

int main() {
    
    //       5 
    //     /   \ 
    //    3     7 
    //   / \   / \ 
    //  2   4 6   8
    
    Node* root = NULL;
    cout<<"Enter elements into BST: "<<endl;
    takeInput(root);
    
    cout<<"Flattening BST to sorted list: "<<endl;
    print(flatten(root));
    return 0;
}