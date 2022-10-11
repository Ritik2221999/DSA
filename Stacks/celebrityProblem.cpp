// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/
#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int> > &M, int a, int b, int n) {
    if(M[a][b] == 1)
        return true;
    else
        return false;
}

int celebrity(vector<vector<int> > &M, int n) {
    stack<int> ids;
    
    // Step: 1) Push all ids into stack
    for(int i=0; i<n; i++) {
        ids.push(i);
    }
    
    // step: 2) compare two elements
    
    while(ids.size() > 1) {
        int a = ids.top();
        ids.pop();
        
        int b = ids.top();
        ids.pop();
        
        if(knows(M, a, b, n)) {
            ids.push(b);
        }
        else {
            ids.push(a);
        }
    }
    
    int candidate = ids.top();
    
    // step: 3) single element is possible to be a celeb candidate so verify it 
    int zeroCount = 0;
    
    // row check
    for(int i=0; i<n; i++) {
        if(M[candidate][i] == 0) {
            zeroCount++;    // checking row that has all zeros
        }
    } 
    // all zeroes
    if(zeroCount != n)
        return -1;
        
    // col check 
    int oneCount = 0;
    
    for(int i=0; i<n; i++) {
        if(M[i][candidate] == 1) {
            oneCount++;
        }
    }
    
    // diagonal element
    if(oneCount != n-1)
        return -1;
    return candidate;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<celebrity(M,n)<<endl;
    }
}