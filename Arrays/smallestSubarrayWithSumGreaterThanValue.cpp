#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(n^2)
int smallestSubWithSum(int *arr, int n, int x) {
    int mini = INT_MAX;
    
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(sum > x) {
                mini = min(mini, j-i+1);   // j-i+1 -> length of subarray
            }
        }
    }
    return mini;
}

// two pinter approach
// Time Complexity - > O(n)
int smallestSubWithSum(int *arr, int n, int x) {
    int mini = INT_MAX;
    int i = 0, j = 0;
    int sum = 0;
    
    while(i<=j && j<n) {
        while(sum<=x && j<n) {
            sum += arr[j++];
        }
        while(sum>x && i<j) {
            mini = min(mini, j-i);
            sum -= arr[i];
            i++;
        }
    }
    return mini;
}

int main() {
    int arr[6] = {1, 4, 45, 6, 0, 19};
    int x = 51;
    
    cout<<"smallest subarray length with given sum value is :"<<smallestSubWithSum(arr, 6, x);
    return 0;
}