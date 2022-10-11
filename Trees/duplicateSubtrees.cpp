// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
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

Node* buildTree(Node* root) {
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    
    root = new Node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter data inserting at left of: "<<data<<endl;
    root -> left = buildTree(root -> left);
    
    cout<<"Enter data inserting at right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

void preorder(Node* root, vector<int> &temp) {
    if(!root)
        return ;
    
    temp.push_back(root -> data);
    preorder(root -> left, temp);
    preorder(root -> right, temp);
}

string solve(Node* root, unordered_map<string, int>& m, vector<Node*> &ans) {
    
    if(!root)
        return "";
        
    string s = "";
    
    // leaf node
    // if(!root -> right && !root -> left) {
    //     s = to_string(root -> data);
    //     return s;
    // }
    
    s = s + to_string(root -> data) + "$";
    s = s + solve(root -> left, m, ans) + "$" ;
    s = s + solve(root -> right, m, ans);
    if(++m[s] == 2) //increase frequency of currently stored nodes in map
        ans.push_back(root);
    return s;
}
    

vector<Node*> printAllDups(Node* root)
{
    // Code here
    vector<Node*> ans;
    unordered_map<string, int> count;
    solve(root, count, ans);
    return ans;
}

int main() {
    
    //        1    
    //       / \    
    //      2   3
    //     / \  
    //   4   5
    
    Node* root = buildTree(root);
    
    cout<<"\nDuplicate subtrees in subtree are: "<<endl;
    vector<Node*> res = printAllDups(root);
    
    vector<vector<int> > ans;
    
    for(int i=0; i<res.size(); i++) {
        vector<int> temp;
        preorder(res[i], temp);
        ans.push_back(temp);
    }
    
    sort(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}