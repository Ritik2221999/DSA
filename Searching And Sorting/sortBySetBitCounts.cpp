// https://www.codingninjas.com/codestudio/problems/sort-an-array-according-to-the-count-of-set-bits_873142

#include<bits/stdc++.h>
using namespace std;

int countsetBits(int a) {
    int cnt = 0;
    
    while(a) {
        if(a % 2 == 1) {
            cnt++;
        }
        a = a/2;
    }
    return cnt;
}

void sortBySetBitCount(int arr[], int n) {
    unordered_map<int, vector<int> > mp;
    int mn = INT_MAX;
    int mx = INT_MIN;
    
    for(int i=0; i<n; i++) {
        int val = countsetBits(arr[i]);
        mp[val].push_back(arr[i]);
        mx = max(mx, val);
        mn = min(mn, val);
        
    }
    int idx = 0;
    // for(int i=mx; i>=mn; i--) {
    //     if(mp.count(i) != 0) {
    //         for(auto &e: mp[i]) {
    //             arr[idx] = e;
    //             idx++;
    //         }
    //     }
    // }
    
    for(auto j=mp.begin(); j!=mp.end(); j++) {
        for(auto k: j -> second) {
            arr[idx] = k;
            idx++;
        }
    }
    return ;
}

int main() {
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sortBySetBitCount(arr, n);
    
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}