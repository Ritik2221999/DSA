// https://www.codingninjas.com/codestudio/problems/convert-min-heap-to-max-heap_630293
#include<bits/stdc++.h>
using namespace std;

void heapify(long *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i  + 2;
    
    if(left < n && arr[largest] < arr[left])
        largest = left;
    if(right < n && arr[largest] < arr[right])
        largest = right;
    
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void minHeapToMaxHeap(long *arr, int n)
{
    //Write your code here
    
    for(int i = (n-1)/2; i>=0; i--) {
        heapify(arr, n, i);
    }
    
}

int main() {
    
     /* Input: min-heap
               1
 
          3         4
 
        6   10    8   5
 
    */
    
    long arr[] = {1, 3, 4, 6, 10, 8, 5 };
    
    cout<<"Min-Heap ->";
    for(auto i: arr)
        cout<<i<<" ";
    cout<<endl;
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    minHeapToMaxHeap(arr, n);
    
    /* Output: max-heap
               10
 
          6         8
 
        1    3    4    5
    */
    
    cout<<"Converting Min-Heap to Max-Heap: "<<endl;
    cout<<"Max-Heap ->";
    for(auto i: arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}