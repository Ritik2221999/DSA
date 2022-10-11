// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#

#include<bits/stdc++.h>
using namespace std;

// top-down approach
int MaxSumRecMem(int arr[], int n, vector<int> &dp) {
    if(n < 0)
        return 0;
    if(n == 0)
        return arr[0];
    if(dp[n] != -1)
        return dp[n];
    
    int steal = arr[n] + MaxSumRecMem(arr, n-2, dp);
    
    int notSteal = MaxSumRecMem(arr, n-1, dp);
    
    dp[n] = max(steal, notSteal);
    return dp[n];
}

// naive approach
int FindMaxSum(int arr[], int n) {
    if(n < 0)
        return 0;
    if(n == 0)
        return arr[0];
        
    int steal = arr[n] + FindMaxSum(arr, n-2);
    
    int notSteal = FindMaxSum(arr, n-1);
    
    return max(steal, notSteal);
}

int main() {
    int arr[] = {5,5,10,100,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> dp(n+1, -1);
    // cout<<FindMaxSum(arr, n-1);
    
    // cout<<MaxSumRecMem(arr, n-1, dp);
    cout<<MaxSumTab(arr, n);
    
    return 0;
}