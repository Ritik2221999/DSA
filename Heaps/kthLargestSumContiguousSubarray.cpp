// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
#include<bits/stdc++.h>
using namespace std;

// Naive Approach
// Time Complexity -> O(n^2(logn))

// int getKthLargest(vector<int> &arr, int k) {
    
//     vector<int> sumStore;
//     int n = arr.size();
    
//     for(int i=0; i<n; i++) {
//         int sum = 0;
        
//         for(int j=i; j<n; j++) {
//             sum += arr[j];
//             sumStore.push_back(sum);
//         }
//     }
    
//     sort(sumStore.begin(), sumStore.end());
    
//     return sumStore[sumStore.size() - k];
// }

// Optimized Appraoch -> MinHeap
int getKthLargest(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    int n = arr.size();
    
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            
            if(minHeap.size() < k) {
                minHeap.push(sum);
            }
            else {
                if(sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}

int main() {
    
    vector<int> arr = {2, 6, 4, 1};
    int k = 3; // kth largest sum in subarray
    
    cout<<"K-th Largest Sum contiguous subarray is: "<<endl;
    cout<<getKthLargest(arr, k);
    
    return 0;
}