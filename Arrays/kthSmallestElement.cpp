#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[],int l, int r, int k) {
    int result = 0;

    // sort the array
    sort(arr, arr+r+1);
    
    while(l != k-1) {
        l++;
    }
    
    result = arr[l];
    
    return result;
}

int main() {
    int n, k;
    cout<<"Enter Number of Elements in an array: "<<endl;
    cin>>n;
    
    int arr[10];
    
    cout<<"Enter the Elements in array: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    cout<<"Enter the position kth smallest element to be found: "<<endl;
    cin>>k;
    
    int ans = kthSmallest(arr, 0, n-1, k);
    cout<<"The kth smallest element is: "<<ans<<endl;
    
    return 0;
}