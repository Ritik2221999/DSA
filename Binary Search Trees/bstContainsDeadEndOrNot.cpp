// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}


bool isDeadEnd(Node *root);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

bool solve(Node* root, int min, int max) {
    if(!root) return false;
    if(min == max) return true;
    
    return solve(root -> left, min, root -> data - 1) ||
           solve(root -> right, root -> data + 1, max);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root, 1, INT_MAX);
}