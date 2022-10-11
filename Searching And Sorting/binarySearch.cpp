#include<bits/stdc++.h>
using namespace std;

int recursiveApproach(int arr[], int low, int high, int key) {

    if(high >= low) {
        int mid = low + (high - low)/2;
        
        if(arr[mid] == key)
            return mid;
            
        // if key is greater than mid
        if(arr[mid] < key)
            return recursiveApproach(arr, mid+1, high, key);
        else
            return recursiveApproach(arr, low, mid-1, key);
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size-1;
    
    // int mid = low + (high - low)/2;
    while(low <= high) {
        int mid = low + (high - low)/2;
        // check if key is present
        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            low = mid+1;
        else
            high = mid-1;
            
        // mid = low + (high - low)/2;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 20};
    int x = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int result = recursiveApproach(arr, 0, n, x);
    int result = binarySearch(arr, n, x);
    
    (result == -1) ? cout<<"Element is not present in array: "<<result
                    : cout<<"Element is present at: "<<result<<endl;
    
    return 0;
}