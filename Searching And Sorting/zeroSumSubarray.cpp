// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#

#include<bits/stdc++.h>
using namespace std;

int findSubarray(vector<int> arr, int n) {
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1; // empty map is also a zero sum subarray
    int count = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        
        if(sum == 0 || mp.find(sum) != mp.end())
            count += mp[sum];
            
        mp[sum]++; // increment the frequency of prefixSum
    }
    return count;
}


int main() {
    vector<int> arr = {6,-1,-3,4,-2,2,4,6,-12,-7};
    
    int n = arr.size();
    cout<<findSubarray(arr, n);
    return 0;
}