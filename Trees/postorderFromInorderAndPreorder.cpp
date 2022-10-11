// https://practice.geeksforgeeks.org/problems/construct-tree-1/1
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

void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
    
    for(int i=0; i<n; i++) {
        nodeToIndex[in[i]] = i;
    }    
}

node* solve(int in[], int pre[], int &index, int inorderStart, 
int inorderEnd, int n, map<int, int> &nodeToIndex) {
    // base case
    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }
    
    // create root node for the element
    int element = pre[index++];
    node* root = new node(element);
    
    // find the element in inorder
    int position = nodeToIndex[element];
    
    // recursive calls
    root -> left = solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);
    root -> right = solve(in, pre, index, position+1, inorderEnd, n, nodeToIndex);
    
    return root;
}

node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    
    // create nodes to index mapping of element
    createMapping(in, nodeToIndex, n);
    node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
    return ans;
}

void printPostOrder(node* root) {
    if(root == NULL)
        return ;
        
    printPostOrder(root -> left);
    printPostOrder(root -> right);
    cout<<root -> data<<" ";
}

int main() {

    int n;
    cout<<"Enter number of elements in inorder and postorder: "<<endl;
    cin>>n;
    
    int inorder[n], preorder[n];
    
    cout<<"Enter elements in inorder: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>inorder[i];
    }
    
    cout<<"Enter elements in preorder: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>preorder[i];
    }
    
    cout<<"\nThe postorder of inorder and preorder is: "<<endl;
    node* root = buildTree(inorder, preorder, n);
    printPostOrder(root);

    return 0;
}