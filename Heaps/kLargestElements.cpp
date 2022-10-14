// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
#include<bits/stdc++.h>
using namespace std;

// Approach-1
// vector<int> kLargest(int arr[], int n, int k) {
   
//     vector<int> ans;
    
//     sort(arr, arr + n, greater<int> ());
    
//     for(int i=0; i<k; i++)
//         ans.push_back(arr[i]);
//   return ans;
// }


// Approach-2 -> Priority_queue
// Time Complexity -> O(NlogK)
vector<int> kLargest(int arr[], int n, int k) {
   vector<int> ans;
   
   priority_queue<int, vector<int>, greater<int> > pq;
	   
    // 	  step: 1) push first k elements in min heap
    for(int i=0; i<k; i++)
        pq.push(arr[i]);
        
    for(int i=k; i<n; i++) {
        if(pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    for(int i=0; i<k; i++) {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int arr[] = {12, 5, 787, 1, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;  // k largest element
    
    vector<int> ans = kLargest(arr, n, k);
    
    cout<<"The k largest element are: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}