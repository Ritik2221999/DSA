// https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values3719/1#

#include<bits/stdc++.h>
using namespace std;

vector<int>PosNegPair(int a[], int n) {
    vector<int> v, ans;
    map<int, int> mp;
    
    for(int i=0; i<n; i++) {
        if(a[i] < 0)
            v.push_back(a[i]); // contains only negative elements
        else
            mp[a[i]]++;  // contains only positive elements and its counts
    }
    
    // now sort the negative vector
    sort(v.begin(), v.end());  // inimum of negative will be at last
    
    for(int i=v.size()-1; i>=0; i--) {
        int data = abs(v[i]);
        if(mp[data] > 0) {  // if v -> (-ve)data is present in mp -> (+ve)data and its count is greater than 0
            ans.push_back(v[i]);  // first insert the negative element
            ans.push_back(data); // then insert the positive element
            mp[data] -= 1;  // if element is found in positive vector now decrement its count bacause it's been pushed inside ans
        }
    }
    return ans;
}

int main() {
    int a[] = {1, -3, 2, 3, 6, -1, -3, 3};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> result = PosNegPair(a, n);
    
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }cout<<endl;
    return 0;
}