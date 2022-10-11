#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    // base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }
    
    if(d > root -> data) {
        // insert at right subtree
        root -> right = insertIntoBST(root -> right, d);
    } else {
        // insert at left subtree
        root -> left = insertIntoBST(root -> left, d);
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

void inorder(Node* root, vector<int> &in) {
    if(root == NULL)
        return ;
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0;
    int k = 0;
    
    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        }
        else {
            ans[k++] = b[j];
            j++;
        }
    }
    
    while(i < a.size()) {
        ans[k++] = a[i];
        i++;
    }
    
    while(j < b.size()) {
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

Node* inorderToBST(int s, int e, vector<int> &in) {
    // base case
    if(s > e)
        return NULL;
    
    int mid = (s + e)/2;
    
    Node* root = new Node(in[mid]);
    
    root -> left = inorderToBST(s, mid-1, in);
    root -> right = inorderToBST(mid+1, e, in);
    
    return root;
}

Node* mergeBST(Node* root1, Node* root2) {
    // step: 1) store inorder of both trees in arrays
    vector<int> bst1, bst2;
    
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    // step: 2) merge both sorted arrays 
    vector<int> merge = mergeArrays(bst1, bst2);
    
    // step: 3) use merged inorder array to build BST 
    int s = 0, e = merge.size()-1;
    return inorderToBST(s, e, merge);
}

void inorderTraversal(Node* root) {
    // base case
    if(root == NULL)
        return ;
    inorderTraversal(root -> left);
    cout<<root -> data<<" ";
    inorderTraversal(root -> right);
}

int main() {
    
    /* Create following tree as first balanced BST
        100
        / \
        50 300
       / \
      20 70
    */
    
    /* Create following tree as second balanced BST
         80
        / \
       40 120
    */
    
    Node* root1 = NULL;
    Node* root2 = NULL;
    
    cout<<"Enter elements into BST-1: "<<endl;
    takeInput(root1);
    
    cout<<"Enter elements into BST-2: "<<endl;
    takeInput(root2);
    
    Node* root = mergeBST(root1, root2);
    
    cout<<"\nFollowing is inorder traversal of merged trees"<<endl;
    inorderTraversal(root);
}