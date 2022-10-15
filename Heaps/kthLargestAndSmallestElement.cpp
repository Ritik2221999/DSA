#include<bits/stdc++.h>
using namespace std;

int kthLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq; //Min-Heap
    
    for(int i=0; i<k; i++)
        pq.push(arr[i]);
        
    for(int i=k; i<=n; i++) {
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    int ans = pq.top();
    return ans;
}

int kthSmallest(int arr[],int n, int k) {
    priority_queue<int> pq; // Max-heap
    
    // step: 1) Store first k elements in Max-Heap
    for(int i=0; i<k; i++)
        pq.push(arr[i]);
    
    // step: 2) now compare k to n element with heap.top()
    for(int i=k; i<=n; i++) {
        if(arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    // step: 3) answer will always be present at heap.top()
    int ans = pq.top();
    return ans;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int k = 3; // 3rd smallest element
    
    cout<<"The: "<<k<<" Smallest element is: "<<endl;
    cout<<kthSmallest(arr, n-1, k);
    
     cout<<"\nThe: "<<k<<" Largest element is: "<<endl;
     cout<<kthLargest(arr, n-1, k);
    
    return 0;
}