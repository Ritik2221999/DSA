// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
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

vector <int> zigZagTraversal(node* root)
{
	// Code here
	vector<int> result;
	
	if(root == NULL)
	    return result;
	    
	queue<node*> q;
	q.push(root);
	
	bool leftToRight = true;
	
	while(!q.empty()) {
	    int size = q.size();
	     vector<int> ans(size);
	     
	   //  level process
	   for(int i=0; i<size; i++) {
	       node* frontNode = q.front();
	       q.pop();
	       
	       //normal insertion or reversal traversal(leftToRight or rightToLeft)
	       int index = leftToRight ? i : size - i - 1;
	       
	       ans[index] = frontNode -> data;
	       
	       if(frontNode -> left)
	            q.push(frontNode -> left);
	       if(frontNode -> right)
	            q.push(frontNode -> right);
	   }
	   //change the direction
	   leftToRight = !leftToRight;
	   
	   for(auto i: ans)
	    result.push_back(i);
	}
	return result;
}

int main() {
    node* root = buildTree(root);
    
    vector<int> ans = zigZagTraversal(root);
    
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}
