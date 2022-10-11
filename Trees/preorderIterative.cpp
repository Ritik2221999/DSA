#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int data) {
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

void preorderIterative(Node* root) {
    if(root == nullptr)
        return ;
    
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty()) {
        Node* curr = st.top();
        st.pop();
        
        cout<<curr -> data<<" ";
        
        if(curr -> right)
            st.push(curr -> right);
        if(curr -> left)
            st.push(curr -> left);
        
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}

int main() {
    
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
    
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    
    root -> left -> left = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> left -> left = new Node(7);
    root -> right -> left -> right = new Node(8);
    
    root -> right -> right = new Node(6);
    
    cout<<"preorder iterative traversal is: "<<endl;
    preorderIterative(root);
    
    return 0;
}