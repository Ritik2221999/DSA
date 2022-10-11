#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    // 0-th based indexing
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    
    // if the largest has been changed since, it was initialized
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  // for its child
    }
}

// Time Complexity -> O(nlogn)
vector<int> heapSort(vector<int>& arr, int n) {
//    buld max heap
    for(int i=n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }
    
//     heap sort
    for(int i = n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        
        // Heapify root element to get highest element at root again
       heapify(arr, i, 0);
    }
    return arr;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    
    heapify(arr, n, 0);
    cout<<"heapifying the array: "<<endl;
    
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    vector<int> ans = heapSort(arr, n);
    cout<<"array after heap sort is: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}