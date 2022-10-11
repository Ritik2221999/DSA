#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
   for(int i=0; i<n-1; i++) {
       bool swapped = false;
       
       for(int j=0; j<n-i-1; j++) {
           if(arr[j] > arr[j+1]) {
               swap(arr[j], arr[j+1]);
               swapped = true;
           }
       }
    //   if no two elements were swapped by inner loop, then beak
       if(swapped == false)
            break;
   }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, n);
    cout<<"bubble sort: "<<endl;
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}