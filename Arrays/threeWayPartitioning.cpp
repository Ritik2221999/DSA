#include<iostream>
using namespace std;

void threeWayPartitioning(int arr[], int n, int a, int b) {
    int l = 0;
    int r = n-1;
    
    for(int i=0; i<=r; i++) {
        if(arr[i] < a) {
            swap(arr[i], arr[l]);
            l++;
        }
        else if(arr[i] > b) {
            swap(arr[i], arr[r]);
            r--;
            i--;
        }
    }
}

int main() {
    int arr[] = {6, 9, 11, 3, 8, 5, 19, 21};
    int n = 8;
    
    threeWayPartitioning(arr, 8, 7, 12);
    
    cout<<"three way partitiong of an array having range 7 and 12 are :"<<endl;
    
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}