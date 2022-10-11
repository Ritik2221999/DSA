#include<bits/stdc++.h>
using namespace std;

int merge(int a[], int temp[], int left, int mid, int right) {
    int i, j, k, inverse = 0;
    i=left;
    j=mid;
    k=left;
    
    while((i<=mid-1) && (j<=right)) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inverse +=  (mid-i);
        }
    }
    
    while(i<=mid-1) {
        temp[k++] = a[i++];
    }
    while(j<=right) {
        temp[k++] = a[j++];
    }
    
    for(int m=left; m<=right; m++) {
        a[m] = temp[m];
    }
    
    return inverse;
}

int mergeSort(int a[], int temp[], int left, int right) {
    int inverse = 0;
    if(left < right) {
        int mid = (left+right)/2;
        
        inverse += mergeSort(a, temp, left, mid);
        inverse += mergeSort(a, temp, mid+1, right);
        inverse += merge(a, temp, left, mid+1, right);
    }
    
    return inverse;
}

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        
        int temp[n];
        cout<<"The count inverse is: "<<endl;
        cout<<mergeSort(a, temp, 0, n-1);
    }
    
    return 0;
}