#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
        
        node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* buildTree(node* root) {
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    
    root = new node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter data inserting at left of: "<<data<<endl;
    root -> left = buildTree(root -> left);
    
    cout<<"Enter data inserting at right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

int ans;
void solve(node* root, int height, int &level) {
    if(!root) return ;
    
    if(ans == 0)
        return ;
    
    if(!root -> left && !root -> right) {
        if(level == -1) {
            level = height;
        }
        else {
            if(height != level) {
                ans = 0;
            }
        }
        return ;
    }
    solve(root -> left, height+1, level);
    solve(root -> right, height+1, level);
}

bool check(node *root)
{
    //Your code here
    int level = -1;
    int height = 0;
    ans = 1;
    solve(root, height, level);
    return ans;
}

int main() {
    node* root = buildTree(root);
    
    if(check(root)) {
        cout<<"\nAll leaf nodes are at same level "<<endl;
    }
    else {
        cout<<"\nAll leaf nodes are not at same level "<<endl;
    }
    
    return 0;
}