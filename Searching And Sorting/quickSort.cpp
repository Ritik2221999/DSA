#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[0];
    
    int count = 0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivot)
            count++;
    }
    
    // place pivot to its right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);
    
    // take care of left and right part
    int i = s, j = e;
    
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] < pivot) {
            i++;
        }
        
        while(arr[j] > pivot) {
            j--;
        }
        
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    // base case
    if(s >= e)
        return ;
    
    // partition
    int p = partition(arr, s, e);
    
    // left partition
    quickSort(arr, s, p-1);
    
    // right partition
    quickSort(arr, p+1, e);
}

int main() {
    int arr[] = {65, 22, 11, 12, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, n-1);
    
    cout<<"Quick sort: "<<endl;
    for(int i=0;i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}