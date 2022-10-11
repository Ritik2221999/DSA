// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1
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

Node* solve(int pre[], int min, int max, int &index, int n) {
    // base case
    if(index >= n) return NULL;
    
    if(pre[index] < min || pre[index] > max)
        return NULL;
        
    Node* root = new Node(pre[index++]);
    
    root -> left = solve(pre, min, root -> data, index, n);
    
    root -> right = solve(pre, root -> data, max, index, n);
    
    return root;
}

void postOrder(Node* root) {
    // base case
    if(!root) return ;
    
    postOrder(root -> left);
    postOrder(root -> right);
    cout<<root -> data<<" ";
}

Node* post_order(int pre[], int size)
{
    //code here
    int index = 0;
    return solve(pre, INT_MIN, INT_MAX, index, size);
}

int main()
{
    int pre[] = { 40, 30, 35, 80, 100 };
 
    int n = sizeof(pre) / sizeof(pre[0]);
 
    cout<<"Postorder from preorder is: "<<endl;
    postOrder(post_order(pre, n));
    return 0;
}