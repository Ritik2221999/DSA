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

void solve(node* root, int k, int &count, vector<int> &path) {
    // base case
    if(root == NULL)
        return ;
    
    path.push_back(root -> data);
    
    // left part
    solve(root -> left, k, count, path);
    
    // right part
    solve(root -> right, k, count, path);
    
    // check for k-sum
    int size = path.size();
    int sum = 0;
    
    for(int i = size - 1; i >= 0; i--) {
        sum += path[i];
        
        if(sum == k) {
            for(int j = i; j<size; j++) {
                cout<<path[j]<<" ";
            }cout<<endl;
            count++;
        }
    }
    path.pop_back();
}

int main() {
    
//            1
//         /     \
//       3        -2
//     /  \      /   \
//   2    1     4     5                        
//       /     / \     \                    
//      1    1   2      6 
    
    
    node* root = buildTree(root);
    
    vector<int> path;
    int count = 0;
    int k = 5;
    
    cout<<"\nThe all k-sum path nodes are: "<<endl;
    solve(root, k, count, path);
    
    cout<<"\nThe total count of k - sum path nodes are: "<<endl;
    cout<<count<<endl;
    
    return 0;
}