#include<bits/stdc++.h>
using namespace std;


// brute force approach
// Time Complexity -> O(n^2)

int maxProfit(int arr[], int n) {
    int maxpro = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int profit = arr[j] - arr[i];
            if(profit > maxpro) {
                maxpro = profit;
            }
        }
    }
    return maxpro;
}


// Optimized approach
// Time Complexity -> O(n)
int maxProfit(int arr[], int n) {
    int miniprice = INT_MAX;
    int maxProfit = 0;
    
    for(int i=0; i<n; i++) {
        if(arr[i] < miniprice) {
            miniprice = arr[i];
        } else if(arr[i] - miniprice > maxProfit) {
            maxProfit = arr[i] - miniprice;
        }
    }
    return maxProfit;
}

int main() {
    int arr[6] = {7,1,5,3,6,4};
    
    cout<<"Maximum profit is: "<<maxProfit(arr, 6);
    return 0;
}