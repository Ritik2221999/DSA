#include<bits/stdc++.h>
using namespace std;


// Brute force approach
// Time Complexity - O(n^2)
int getPairsCount(int arr[], int n, int k) {
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == k) {
              count++;
            }
        }
    }
    
    return count;
}


// Optimized approach
// Time Complexity -> O(n)

int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> m;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            int b = k - arr[i];
            if(m[b]) {
                ans += m[b];
            }
            m[arr[i]]++;
        }
        return ans;
    }

int main() {
    int arr[4] = {1, 5, 7, 1};
    int k;
    cout<<"Enter the values of k: "<<endl;
    cin>>k;
    
    cout<<"Count pairs with given sum is: "<<getPairsCount(arr, 4, k);
    return 0;
}