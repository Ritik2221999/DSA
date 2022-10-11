#include<bits/stdc++.h>
using namespace std;

int recursiveLinearSearch(int arr[], int size, int key) {
    // base case
    if(size == 0)
        return -1;
    if(arr[size] == key)
        return size;
    else {
        return recursiveLinearSearch(arr, size-1, key);
    }
}

int linearSearch(int arr[], int n, int x) {
    for(int i=0; i<n; i++) {
        if(arr[i] == x)
            return i;
    } 
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 20};
    int x = 20;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // int result = linearSearch(arr, n, x);
    int result = recursiveLinearSearch(arr, n, x);
    
    (result == -1) ? cout<<"Element is not present in array: "<<result
                    : cout<<"Element is present at: "<<result<<endl;
    
    return 0;
}