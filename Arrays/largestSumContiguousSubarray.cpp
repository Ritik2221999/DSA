#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxSum = INT_MIN;
    int iterate = 0;
    
    for(int i=0; i<n; i++) {
        iterate = iterate + arr[i];
        
        if(maxSum < iterate) {
            maxSum = iterate;
        }
        
        if(iterate < 0) {
            iterate = 0;
        }
    }
    
    return maxSum;
}


int main() {
    int arr[5] = {1, 2, 3, -2, 5};
    
    int result = maxSubarraySum(arr, 5);
    cout<<"Maximum subarray sum using kadane's algo is: "<<result << endl;

    
    return 0;
}