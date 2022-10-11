// https://practice.geeksforgeeks.org/problems/median-of-bst/1
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


void countNodes(Node* root, int &k) {
    if(!root) return ;
    
    countNodes(root -> left, k);
    k++;
    countNodes(root -> right, k);
}

void func(Node* root, Node* &curr, Node* &prev, int &count, int k, int &flag) {
    // base case
    if(!root) return ;
    
    func(root -> left, curr, prev, count, k, flag);
    
    if(prev == NULL) {
        count++;
        prev = root;
    }
    else if(count == k) {
        count++;
        curr = root;
        flag = 1;
        return ;
    }
    else if(flag == 0) {
        count++;
        prev = root;
    }
    
    func(root -> right, curr, prev, count, k, flag);
}


float findMedian(struct Node *root)
{
  //Code here
  int n = 0;
  countNodes(root, n);
  
  Node* curr = NULL;
  Node* prev = NULL;
  
  int count = 1;
  int x = (n/2) + 1;
  int flag = 0;
  
  func(root, curr, prev, count, x, flag);
  
    if(n&1) {
      float ans = (curr -> data) * 1.0;
      return ans;
    }
    else {
      float ans = ((curr -> data + prev -> data) * 1.0) / 2.0;
      return ans;
    }
}

int main() {
    
//        6
//      /   \
//    3      8   
//  /  \    / \
// 1    4  7   9
    
    Node* root = NULL;
    
    cout<<"Enter elements into BST: "<<endl;
    takeInput(root);
    
    cout<<"Median of BST is: "<<endl;
    cout<<findMedian(root);
    
    return 0;
}