#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr, int n) {
    unordered_map<int, int> mp;
    
    int ans = -1;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    
    for(auto it: mp) {
        if(it.second > n/2) {
            ans = it.first;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 1, 3, 3, 2};
    int n = arr.size();
    
    cout<<"Element which appears in majority is: "<<endl;
    cout<<majorityElement(arr, n);

    
    return 0;
}