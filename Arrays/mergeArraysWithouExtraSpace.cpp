#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    int i = n-1, j = m-1;
    int k = n+m-1;
    
    while(i>=0 && j>=0) {
        if(arr2[j] > arr1[i]) {
            arr1[k] = arr2[j];
            j--;
            k--;
        }
        else {
            arr1[k] = arr1[i];
            i--;
            j--;
        }
        
        while(j>=0) {
            arr1[k] = arr2[j];
            j--;
            k--;
        }
    }
}

void printArray(int arr1[], int n, int m) {
    int k = n+m;
    sort(arr1, arr1+k);
    
    cout<<"The merged sorted arrays is: "<<endl;
    for(int i=0; i<k; i++) {
        cout<<arr1[i]<<" ";
    }cout<<endl;
}


int main() {
    int arr1[4] = {1, 3, 5, 7};
    
    cout<<"First array is: "<<endl;
    for(int i=0; i<4; i++) {
        cout<<arr1[i]<<" ";
    }cout<<endl;
    
    int arr2[5] = {0, 2, 6, 8, 9};
    
    cout<<"Second array is: "<<endl;
    for(int i=0; i<5; i++) {
        cout<< arr2[i]<<" " ;  
    }cout<<endl;
    
    merge(arr1, arr2, 4, 5);
    printArray(arr1, 4, 5);
    
    return 0;
}