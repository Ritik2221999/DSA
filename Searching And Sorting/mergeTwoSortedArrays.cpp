#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    // code here
    int i = n-1, j = m-1;
    int k = n+m-1;
    
    while(i>=0 && j>=0) {
        if(arr2[j] > arr1[i]) {
            arr1[k] = arr2[j];
            j--;
            k--;
        }
        else {
            arr1[k] = arr1[i];
            i--;
            j--;
        }
        
        while(j>=0) {
            arr1[k] = arr2[j];
            j--;
            k--;
        }
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    
    int k = n+m-1;
    merge(arr1, arr2, n, m);
    
    sort(arr1, arr1+k);
    for(int i=0; i<k; i++) {
        cout<<arr1[i]<<" ";
    }cout<<endl;
    
    return 0;
}