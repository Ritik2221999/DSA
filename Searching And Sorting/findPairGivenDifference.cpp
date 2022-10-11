#include<bits/stdc++.h>
using namespace std;

// naive approach
// Time Complexity -> O(n^2)
bool findPair(int arr[], int N, int size) {
    for(int i=0; i<size; i++) {
        int temp = arr[i];
        
        for(int j = i+1; j<size; j++) {
            if(abs(temp - arr[j]) == N)
                return true;
        }
    }
    return false;
}

// Time Complexity - > O(n)
bool findPair(int arr[], int N, int size) {
    unordered_map<int, int> mp;
    
    int flag = -1;
    for(int i=0; i<size; i++) {
        mp[arr[i]] = 1;
    }
    
    for(int i=0; i<size; i++) {
        if(mp[arr[i]] + N) {  // if the element is found in map
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        return true;
    return false;
}

// Time Complexity - > O(nlogn)
bool findPair(int arr[], int N, int size) {
    sort(arr, arr+size);
    int f = -1;
    
    for(int i=0; i<size; i++) {
        int idx = upper_bound(arr+i+1, arr+size, N+arr[i]) - arr - 1;
        if(arr[idx] - arr[i] == N) {
            f = 1;
            break;
        }
    }
    return f;
}

int main() {
    int arr[] = {5, 20, 3, 2, 5, 80};
    int L = sizeof(arr)/sizeof(arr[0]);
    
    int N = 78; // difference of two element to be found
    
    cout<<findPair(arr,N, L);
    return 0;
}
