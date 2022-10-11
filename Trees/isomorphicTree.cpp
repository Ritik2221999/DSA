// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
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

bool isIsomorphic(node *root1,node *root2)
{
    //add code here.
    if(!root1 && !root2) return true;
    if(!root1 or !root2) return false;
    if(root1 -> data != root2 -> data) return false;
    
    bool a = isIsomorphic(root1 -> left, root2 -> left) && isIsomorphic(root1 -> right, root2 -> right);
    bool b = isIsomorphic(root1 -> left, root2 -> right) && isIsomorphic(root1 -> right, root2 -> left);
    return a or b;
}

int main() {
    
// T1    1     T2:    1
//     /  \         /   \
//    2    3       3     2
//   /                    \
//   4                     4
    
    cout<<"Enter data for tree T1: "<<endl;
    node* root1 = buildTree(root1);
    
    cout<<"\nEnter data for tree T2: "<<endl;
    node* root2 = buildTree(root2);
    
    if(isIsomorphic(root1, root2)) {
        cout<<"\nYes tree is Isomorphic: "<<endl;
    }
    else {
        cout<<"\nNo tree is not isomorphic: "<<endl;
    }
    
    return 0;
}