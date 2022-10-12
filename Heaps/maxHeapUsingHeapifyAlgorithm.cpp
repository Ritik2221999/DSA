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

// Time Complexity -> O(n)
// Space Complexity -> O(n)
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    
    // 1-Based indexing
    int left = 2 * i;
    int right = 2 * i + 1;
    
    if(left <= n && arr[largest] < arr[left])
        largest = left;
        
    if(right <= n && arr[largest] < arr[right])
        largest = right;
        
    // this means the is not the same node which was previously largest
    if(largest != i) {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}


int main() {
    
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    
    // leaf nodes are from (n/2)+1 to n...
    // perform reverse order traversal from non-leaf and heapify each node
    for(int i=n/2; i>0; i--) {
        maxHeapify(arr, n, i);
    }
    
    cout<<"Printing the Max-Heap using Heapify Algorithm: "<<endl;
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}