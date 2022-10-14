#include<bits/stdc++.h>
using namespace std;

// naive approach
// Time Complexity -> O(n*k)
void printKMax(int arr[], int n, int k) {
    int j, i, maxi;
    
    for(i=0; i<=n-k; i++) {
        maxi = arr[i];
        for(j=1; j<k; j++) {
            if(arr[i+j] > maxi)
                maxi = arr[i+j];
        }
        cout<<maxi<<" ";
    }
}

// Using priority queue
// Time Complexity -> O(n*logn)
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // Pair<int, int> contains (nums[i], index)
    priority_queue<pair<int, int> > heap;
    
    vector<int> ans; // store all maximum values for all sliding windows
    
    for(int i=0; i<nums.size(); i++) {
        while(!heap.empty() && heap.top().second <= (i-k)) // pop the root (max_element), if outside sliding window 
            heap.pop();
        heap.push(make_pair(nums[i], i)); // push curr element along with its index at heap
        if(i >= k-1) // store max in the window if we have a valid window (based on size k)
            ans.push_back(heap.top().first);
    }
    return ans;
}

int main() {
    
    
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int K = 3;
    vector<int> ans = maxSlidingWindow(nums, K);
    
    cout<<"Maximum of all subarrays of size: "<<K<<" are: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    // naive approach
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int K = 3;
    // printKMax(arr, n, K);
    
    return 0;
}