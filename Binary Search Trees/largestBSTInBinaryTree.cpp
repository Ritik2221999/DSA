// https://practice.geeksforgeeks.org/problems/largest-bst/1

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


class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(Node* root, int &ans) {
    // base case
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};


    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);
    
    info currNode;
    
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root -> data, right.maxi);
    currNode.mini = min(root -> data, left.mini);
    
    if(left.isBST && right.isBST && (root -> data > left.maxi && root -> data < right.mini)) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }

    // update answer
    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBst(Node *root)
{
	//Your code here
	int maxSize = 0;
	info temp = solve(root, maxSize);
	return maxSize;
}


int main() {
    
/* Let us construct the following Tree
        60
       /  \
      65  70
     /
    50 */
    
    Node* root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    
    cout<<"Largest bst subtree size is: "<<endl;
    cout<<largestBst(root)<<endl;
    return 0;
}