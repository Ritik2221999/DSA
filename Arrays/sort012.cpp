#include<bits/stdc++.h>
using namespace std;

void sort012(int a[], int n) {
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    
    // loop through all elemenets in array and count number of zero, ones and twos
    for(int i=0; i<n; i++) {
        if(a[i] == 0)
            zeroCount++;
        else if(a[i] == 1)
            oneCount++;
        else if(a[i] == 2)
            twoCount++;
    }
    
    for(int i=0; i<zeroCount; i++) {
        a[i] = 0;
    }
    for(int i=zeroCount; i<(zeroCount + oneCount); i++) {
        a[i] = 1;
    }
    
    for(int i=(zeroCount + oneCount); i<n; i++) {
        a[i] = 2;
    }
    
    
}

int main() {
    int arr[5] = {0, 2, 1, 2, 0};
    
    cout<<"Sorted Zeros ones and two's are:";
    sort012(arr, 5);
    
    for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}