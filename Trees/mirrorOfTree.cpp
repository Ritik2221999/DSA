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
        
    cout<<"Enter data for inserting at left of: "<<data<<endl;
    root -> left = buildTree(root -> left);
    
    cout<<"Enter data for inserting at right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

// void levelOrder(node* root) {
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);
    
//     while(!q.empty()) {
//         node* temp = q.front();
//         q.pop();
        
//         if(temp == NULL) {
//             cout<<endl;
            
//             if(!q.empty()) {
//                 q.push(NULL);
//             }
//         }
//         else {
//             cout<<temp -> data<<" ";
            
//             if(temp -> left != NULL)
//                 q.push(temp -> left);
                
//             if(temp -> right != NULL)
//                 q.push(temp -> right);
//         }
//     }
// }

void inorder(node* root) {
    if(root == NULL)
        return ;
        
    inorder(root -> left);
    cout<<root-> data<<" ";
    inorder(root -> right);
}

void mirror(node* root) {
    // base case
    if(root == NULL)
        return ;
    mirror(root -> left);
    mirror(root -> right);
    swap(root -> left, root -> right);
}

int main() {
    node* root = NULL;
    
    root = buildTree(root);
    
    cout<<"inorder Mirror of tree is: "<<endl;
    mirror(root);
    
    inorder(root);
    
    return 0;
}