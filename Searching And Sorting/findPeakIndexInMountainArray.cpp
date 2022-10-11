#include<bits/stdc++.h>
using namespace std;

// naive approach
// Time Complexity -> O(n)
int peakIndexInMountainArray(vector<int> &arr) {
    int n = arr.size()-1;
    
    // first or last element is peak element
    if(n == 1)
        return 0;
    if(arr[0] >= arr[1])
        return 1;
    if(arr[n-1] >= arr[n-2])
        return n-1;
        
    for(int i=0; i<n-1; i++) {
        if(arr[i] >= arr[i-1] && arr[i] > arr[i+1])
            return i;
    }
}

// optimized approach
// Time Complexity -> O(logn)
int peakIndexInMountainArray(vector<int> &arr) {
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end - start)/2;
    while(start < end) {
        if(arr[mid] <arr[mid+1])
            start = mid+1;
        else
            end = mid;
        mid = start + (end - start)/2;
    }
    return arr[start];
}

int main() {
    vector<int> arr = {10, 20, 15, 2, 23, 90, 67};
    cout<<"The peak index in Mountain array is: "<<endl;
    cout<<peakIndexInMountainArray(arr);
    return 0;
}