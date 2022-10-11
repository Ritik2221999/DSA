#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
};

// Time Complexity -> O(n)
// Space Complexity -> O(1)
void morris(node* root) {
    // base case
    if(root == NULL)
        return ;
        
    node* curr , *pred;
    
    curr = root;
    
    while(curr != NULL) {
        if(curr -> left == NULL) {
            cout<<curr -> data<<" ";
            curr = curr -> right;
        }
        else {
            // find predecessor -> move 1 time left then while curr -> right != NULL move right, check for cycle also
            pred = curr -> left;
            while(pred -> right != NULL && pred -> right != curr)
                pred = pred -> right;
                
            if(pred -> right == NULL) {
                pred -> right = curr;
                curr = curr -> left;
            }
            else {
                pred -> right = NULL;
                cout<<curr -> data<<" ";
                curr = curr -> right;
            }
        }
    }
}

node* newNode(int data) {
    node* temp = new node;
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}

int main() {
    
    node* root = newNode(4);
    root -> left = newNode(2);
    root -> right = newNode(5);
    root -> left -> left = newNode(1);
    root -> left -> right = newNode(3);
    
    cout<<"morris(inorder) traversal is: "<<endl;
    morris(root);
    
    return 0;
}