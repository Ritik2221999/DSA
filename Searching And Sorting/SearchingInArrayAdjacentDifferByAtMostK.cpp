#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int k, int x, int n) {
    
    int i=0;
    while(i < n) {
        if(arr[i] == x)
            return i;
        // we are using max here so that 'i' need to atleast move 1 step ahead
        i = i + max(1, abs(arr[i] - x)/k);
    }
    
    cout<<"Number is not present: "<<endl;
    return -1;
    
}

int main() {
    int arr[] = {20, 40, 50, 70, 70, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int x = 60;  // element to find
    int k = 20; // difference between adjacent elements
    
    cout<<"the index value of "<<x<<" is: "<<endl;
    cout<<search(arr, k, x, n);
    return 0;
}
