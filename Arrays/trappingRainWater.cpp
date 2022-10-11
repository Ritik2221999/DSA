#include<bits/stdc++.h>
using namespace std;

// Brute fotrce approach
// Time Complexity -> O(n^2)
int trappingWater(int arr[], int n) {
    
        if(n <= 2)
            return 0;
        int trappedWater = 0;
        for (int i = 0; i < n; i++) {
            
            int left_max = 0, right_max = 0;
            
            for (int j = i; j >= 0; j--) {
                left_max = max(arr[j],left_max);
            }

            for (int j = i; j < n; j++) {
                right_max = max(arr[j], right_max);
            }
			//Find volume
            trappedWater += min(left_max, right_max) - arr[i];
        }
        return trappedWater;
}

// two pointers approach
// Time Complexity -> O(n)
long long trappingWater(int height[], int n) {
    long long int trappedWater = 0;
    int leftMaxHeight = 0, rightMaxHeight = 0;
    int left = 0, right = n-1;
    
    while(left <= right) {
        if(height[left] < height[right]) {
            
            if(height[left] > leftMaxHeight) {
                leftMaxHeight = height[left];
            } 
            else {
                trappedWater += leftMaxHeight - height[left];
            }
            left = left + 1;
        }
        else  {
            if(height[right] > rightMaxHeight) {
                rightMaxHeight = height[right];
            }
            else {
                trappedWater += rightMaxHeight - height[right];
            }
            right = right - 1;
        }
    }
    return trappedWater;
}

int main() {
    int arr[6] = {3,0,0,2,0,4};
    int result = trappingWater(arr, 6);
    cout<<"Output of trapping rain water is: "<<result;
    return 0;
}