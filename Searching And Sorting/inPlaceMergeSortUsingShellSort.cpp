#include<bits/stdc++.h>
using namespace std;

// O(n log_2n)
void inPlaceMerge(int arr[], int start, int mid, int end) {
    int len = end - start + 1;
    
    int h = ceil(len/2.0);
    
    while(h >= 1) {
        int idx = start;
        
        while(idx + h <= end) {
            if(arr[idx] > arr[idx + h]) {
                swap(arr[idx], arr[idx + h]);
            }
            idx = idx + 1;
        }
        
        if(h == 1)
            break;
            
        h = ceil(h/2.0);
    }
}

// log_2n * O(n log_2n) = O(n (log_2n)^2)
void inPlaceMergeSort(int arr[], int low, int high) {
    if(low == high)
        return ;
    
    int mid = (low + high)/2;
    
    inPlaceMergeSort(arr, low, mid);
    
    inPlaceMergeSort(arr, mid+1, high);
    
    inPlaceMerge(arr, low, mid, high);
}

int main() {
    int arr[] = {5, 4, 1, 6, 3, 2, 8, 7};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Array before sorting : \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }cout<<endl;
    
    inPlaceMergeSort(arr,0, n-1);
    
    cout << "Array before sorting : \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }cout<<endl;
    
    return 0;
}