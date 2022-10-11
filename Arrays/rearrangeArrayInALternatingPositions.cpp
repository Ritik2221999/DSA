#include<iostream>
using namespace std;

void rearrange(int arr[], int n) {
    int i = -1;
    
    // Swap all positive integers to the beginning and the negative to end of array
    for(int j=0; j<n; j++) {
        if(arr[j] > 0) {
             i = i+1;
            swap(arr[i], arr[j]);
        }
       
    }
    int pos_index = 0, neg_index = i+1;
    
    while(neg_index < n && neg_index > pos_index && arr[neg_index] < 0) {
        swap(arr[neg_index], arr[pos_index]);
        pos_index = pos_index + 2;
        neg_index = neg_index + 1;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main() {
    int arr[6] = {1, 2, 3, -4, -1, 4};
    
    cout<<"The elements in array are: "<<endl;
    printArray(arr, 6);
    
    rearrange(arr, 6);
    
    cout<<"Array after rearranging is: "<<endl;
    
    printArray(arr, 6);
    
    return 0;
}