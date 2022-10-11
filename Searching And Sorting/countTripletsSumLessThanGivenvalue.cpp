#include<bits/stdc++.h>
using namespace std;

// naive approach
// Time COmplexity -> O (n^3)
// int countTriplets(int arr[], int n, int sum) {
//     int result = 0;
//     for(int i=0;i<n-2; i++) {
//         for(int j=i+1; j<n-1; j++) {
//             for(int k=j+1; j<n; j++) {
//                 if(arr[i] + arr[j] + arr[k] < sum) {
//                     result++;
//                 }
//             }
//         }
//     }
//     return result;
// }

int countTriplets(int arr[], int n, int sum) {
    sort(arr, arr+n);
    int result = 0;
    
    for(int i=0; i<n-2; i++) {
        int low = i+1, high = n-1;
        
        while(low < high) {
            if(arr[i] + arr[low] + arr[high] >=sum) {
                high--;
            }
            else {
                result += high - low;
                low++;
            }
        }
    }
    return result;
}

int main() {
    int arr[] = {5, 1, 3, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 12;
    
    cout<<countTriplets(arr, n, sum);
    
    return 0;
}