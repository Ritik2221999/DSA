#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n) {
    int s=0, e=n-1;
    
    while(s<=e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    
    for(int i=1; i<n; i++) {
        swap(arr[i], arr[n-1]);
        n--;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main() {
    // int arr[5] = {1, 2, 3, 4, 5};
    int arr[8] = {9, 8, 7, 6, 4, 2, 1, 3};
    
    rotate(arr, 8);
    cout<<"Cyclically rotate array bby one position is: "<<endl;
    printArray(arr, 8);
}