// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#

#include<bits/stdc++.h>
using namespace std;

// optimized approach
// Space Complexity > O(1)
int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    int i = n-1;
    int j = 0;
    
    while(i >= 0 && j < m) {
        if(arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
        else {
            i--;
            j++;
        }
    }
    
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
    
    if(k <= n) {
        return arr1[k-1];
    }
    return arr2[k-n-1];
}

// naive approach
int kthElement(int arr1[], int arr2[], int n, int m, int target) {
    int i=0, j=0;
    int k = 0;
    int size = n+m;
    int arr3[size];
    
    while(i < n && j < m) {
        if(arr1[i] > arr2[j]) {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        else {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
    }
    
    
    while(i < n) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    
    while(j < m) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    
    int ele = 0;
    for(int i=0; i<k; i++) {
        if(i == target) {
            ele = arr3[i-1];
        }
    }
    return ele;
}


int main(){
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int index = 5;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    
    cout<<kthElement(arr1, arr2, n, m, index);
    return 0;
}