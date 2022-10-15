// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    
    // 0-based indxing
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && arr[largest] < arr[left])
        largest = left;
        
    if(right < n && arr[largest] < arr[right])
        largest = right;
        
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b, int n, int m) {
    
    vector<int> ans;
    
    // step: 1) push array a and array b elements into ans array
    for(auto i: a)
        ans.push_back(i);
        
    for(auto i: b)
        ans.push_back(i);
        
    int size = ans.size();
    
    // now heapify(or max-heap) ans array -> (0 - based indexing)
    for(int i = (size / 2) - 1; i>=0; i--) {
        heapify(ans, size, i);
    }
    return ans;
}

void printArray(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main() {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    
    int n = a.size();
    int m = b.size();
    
    vector<int> ans = mergeArrays(a, b, n, m);
    cout<<"After merging two binary max heaps: "<<endl;
    printArray(ans);
    
    return 0;
}