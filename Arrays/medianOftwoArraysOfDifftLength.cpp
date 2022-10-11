#include<bits/stdc++.h>
using namespace std;

int find_median(int num1[], int num2[], int n, int m) {
    int finalArray[n+m];
    int i=0, j=0, k=0;
    
    while(i < n && j < m) {
        if(num1[i] < num2[j]) {
            finalArray[k++] = num1[i++];
        }
        else {
            finalArray[k++] = num2[j++];
        }
    }
    
    while(i<n) {
        finalArray[k++] = num1[i++];
    }
    
    while(j<m) {
        finalArray[k++] = num2[j++];
    }
    n = n+m;
    
    // for even length
    if(n%2 == 1) {
        return finalArray[((n+1)/2)-1];
    }
    // for odd length
        return (finalArray[(n/2)-1] + finalArray[n/2])/2;
}

int main() {
    int num1[] = {1, 4, 7, 10, 12};
    int num2[] = {2, 3, 6, 15};
    
    int n = sizeof(num1)/sizeof(num1[0]);
    int m = sizeof(num2)/sizeof(num2[0]);
    
    cout<<"median of two sorted array of different lengths is: "<<find_median(num1, num2, n, m);
    return 0;
}