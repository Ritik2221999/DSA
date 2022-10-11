// https://practice.geeksforgeeks.org/problems/burning-tree/1
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

node* createParentMapping(node* root, int target, map<node*, node*> &nodeToParent) {
    
    node* res = NULL;
    queue<node*> q;
    q.push(root);
    
    nodeToParent[root] = NULL;
    
    while(!q.empty()) {
        node* front = q.front();
        q.pop();
        
        if(front -> data == target) {
            res = front;
        }
        
        if(front -> left) {
            nodeToParent[front -> left] = front;
            q.push(front -> left);
        }
        
        if(front -> right) {
            nodeToParent[front -> right] = front;
            q.push(front -> right);
        }
    }
    return res;
}

int burnTrees(node* root, map<node*, node*> &nodeToParent) {
    map<node*, bool> visited;
    queue<node*> q;
    
    q.push(root);
    
    visited[root] = true;
    
    int ans = 0;
    
    while(!q.empty()) {
        int size = q.size();
        
        bool flag = 0;
        
        for(int i=0; i<size; i++) {
            // process neighbouring nodes
            node* front = q.front();
            q.pop();
            
            if(front -> left && !visited[front -> left]) {
                flag = 1;
                q.push(front -> left);
                visited[front -> left] = true;
            }
            
            if(front -> right && !visited[front -> right]) {
                flag = 1;
                q.push(front -> right);
                visited[front -> right] = true;
            }
            
            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        
        if(flag == 1)
            ans++;
    }
    return ans;
}

int minTime(node* root, int target) {
    // ALgorithm
    // Step: 1) Create nodeToParent mapping
    // Step: 2) find the target node
    // Step: 3) burn the tree in min time
    
    map<node*, node*> nodeToParent;
    
    node* targetNode = createParentMapping(root, target, nodeToParent);
    
    int ans = burnTrees(targetNode, nodeToParent);
    
    return ans;
}

int main() {
    
//           1
//         /   \
//       2      3
//     /  \      \
//   4    5      6
//       / \      \
//      7   8      9
//                  \
//                   10
    
    node* root = buildTree(root);
    
    cout<<"\nMinimum time to burn the binary tree is: "<<endl;
    
    int targetNode = 8;
    
    cout<<minTime(root, targetNode)<<endl;
    
    return 0;
}