#include<bits/stdc++.h>
using namespace std;

int getMin(int arr[], int n) {
    int min = INT_MAX;
    
    for(int i=0; i<n; i++) {
        // min = min(min, arr[i])
        if(arr[i]<min) {
            min = arr[i];
        }
    }
    return min;
}

int getMax(int arr[], int n) {
    int max = INT_MIN;
    
    for(int i=0; i<n; i++) {
        // max = max(max, arr[i])
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[5] = {12, 1234, 45, 67, 1};
    cout<<"Minimum element in array is: "<<getMin(arr, 5)<<endl;
    cout<<"Maximum element in array is: "<<getMax(arr, 5)<<endl;
}
