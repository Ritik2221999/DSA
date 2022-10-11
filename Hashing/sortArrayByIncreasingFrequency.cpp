// https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> mp;
    vector<int> ans;
    
    for(auto x: nums) {
        mp[x]++;
    }
    
    sort(nums.begin(), nums.end(), [&](int a, int b) {  // lambda expression
    // mp[a] & mp[b] contains frequency and a, b denotes array elements
    // if frequency is not same then sort the element which have less freqency than other element
    // if frequency is same then arrange the element which is greater i/e. decreasing order
        return mp[a] != mp[b] ? mp[a] < mp[b] : a > b;
    });
    return nums;
}

int main() {
    vector<int> nums = {1,1,2,2,2,3};
    vector<int> result = frequencySort(nums);
    
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    return 0;
}