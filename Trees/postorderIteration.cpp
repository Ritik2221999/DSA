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

void postorderIteration(Node* root) {
    if(root == nullptr)
        return ;
        
    stack<Node*> st;
    st.push(root);
    
    // create another stack to store postorder traversal
    stack<int> out;
    
    while(!st.empty()) {
        Node* curr = st.top();
        
        st.pop();
        
        out.push(curr -> data);
        
        if(curr -> left)
            st.push(curr -> left);
            
        if(curr -> right)
            st.push(curr -> right);
    }
    
    while(!out.empty()) {
        cout<<out.top()<<" ";
        out.pop();
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
    
    cout<<"postorder iterative traversal is: "<<endl;
    postorderIteration(root);
    
    return 0;
}