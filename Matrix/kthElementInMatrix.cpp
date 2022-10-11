#include<bits/stdc++.h>
using namespace std;
#define MAX 4

// brute force approach
// time Complexity -> O(n^2)
int kthSmallest(int mat[MAX][MAX], int n, int k) {
    vector<int> ans;
    
    for(int i=0; i<n; i++ ) {
        for(int j=0; j<n; j++) {
                ans.push_back(mat[i][j]);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    return ans[k-1];
}

// binary search approach
// time Complexity -> O(n)
int kthSmallest(int mat[MAX][MAX], int n, int k) {
    if(k == 0 || k > n*n || n == 0)
        return -1;
        
    if(k == 1)
        return mat[0][0];
        
    // initialize smallest and largest element from matrix
    int low = mat[0][0];
    int high = mat[n-1][n-1];
    
    while(low < high) {
        int mid = low + (high - low)/2;
        int count = 0;
        int j = n-1;
        
        // find how many numbers greater than mid between low and high
        for(int i=0; i<n; i++) {
            while(j>=0 && mat[i][j] > mid) {
                j--;
            }
            count += (j+1);
        }
        
        if(count < k)
            low = mid+1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int n = 4;
    int mat[4][4] = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94 }  
    };
    int k;
    cout<<"Enter the kth smallest element position: "<<endl;
    cin>>k;
    
    int result;
    result = kthSmallest(mat, n, k);
    cout<<"The smallest element at: "<<k<<"th "<<"position is: "<<result<<endl;
    
    return 0;
}