#include<bits/stdc++.h>
using namespace std;

// partition process of quicksort
void rearrangeArray(int arr[], int n) {
    int j=0;
    for(int i=0; i<n; i++) {
        if(arr[i] < 0) {
            if (i != j) {
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}

void printArray(int a[], int n) {
    for(int i=0;i<n; i++) {
        cout<<a[i]<<" ";
    }cout<<endl;
}

int main() {
    int arr[9] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    
    rearrangeArray(arr, 9);
    cout<<"all negative elements to right side of array are: "<<endl;
    printArray(arr, 9);
    
    return 0;
}

// using two pointer approach

void rearrangeArray(int arr[], int n) {
   int left = 0, right = n-1;
   
   while(left <= right) {
       if(arr[left] < 0 && arr[right] < 0) {
           left++;
       }
       else if(arr[left] > 0 && arr[right] < 0) {
           swap(arr[left], arr[right]);
           left++;
           right--;
       }
       else if(arr[left] > 0 && arr[right] > 0) {
           right--;
       }
       else {
           left++;
           right--;
       }
   }
   
}