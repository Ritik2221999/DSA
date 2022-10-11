#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
   for(int i=1;i<n; i++) {
       int temp = arr[i];
       int j = i-1;
       for(; j>=0; j--) {
            //   shifting element
            if(arr[j] > temp)
                arr[j+1] = arr[j];
           else {
               break;  // next element is already in sorted position
           }
        }
        arr[j+1] = temp;  // temp > arr[j]
   }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr, n);
    cout<<"insertion sort: "<<endl;
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}