#include<bits/stdc++.h>
using namespace std;

class Heap {
    public:
        int arr[100];
        int size;
        
        Heap() {
            arr[0] = -1;
            size = 0;
        }
};

// Time Complexity of Heapify -> O(logn)
void heapify(int arr[], int n, int i) {
    int largest = i;
    
    int left = 2 * i;
    int right = 2 * i + 1;
    
    if(left < n && arr[largest] < arr[left])
        largest = left;
        
    if(right < n && arr[largest] < arr[right])
        largest = right;
        
        // previous largest's value when initialized and current largest's value are not same
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    
    while(size > 1) {
        // step: 1) Swap the elements
        swap(arr[size], arr[1]);
        size--; // remove the last element 
        
        // step: 2) heapify
        heapify(arr, size, 1); // 1-based indexing
    }
}

void printHeap(int arr[], int n) {
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main() {
    int arr[6] = {-1, 70, 60, 55, 45, 50};
    int n = 5;
    
    cout<<"Elements are: "<<endl;
    printHeap(arr, n);
    
    heapSort(arr, n);
    
    cout<<"After implementing heap sort: "<<endl;
    printHeap(arr, n);
    
    return 0;
}