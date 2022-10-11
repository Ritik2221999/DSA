#include<bits/stdc++.h>
using namespace std;

int minSwap(int *arr, int n, int k) {
    int count = 0;
    
    // calculating total number of elements less than equal to k
    for(int i=0; i<n; i++) {
        if(arr[i] <= k) {
            ++count;
        }
    }
    // counting total no of elements greater than k in a window of size count
    int badAns = 0;
    for(int i=0; i<count; i++) {
        if(arr[i] > k) {
            ++badAns;
        }
    }
    
    // sliding window
    int ans = badAns;
    for(int i=0, j = count; j<n; ++i, ++j) {
        if(arr[i] > k) {
            --badAns;
        }
        if(arr[j] > k) {
            ++badAns;
        }
        ans = min(ans, badAns);
    }
    return ans;
}

int main() {
    int arr[5] = {2, 1, 5, 6, 3};
    int k = 3;
    
    cout<<"the minimum number of swaps required to bring all the numbers less than or equal to k together is: ";
    cout<<minSwap(arr, 5, k)<<endl;
    return 0;
}