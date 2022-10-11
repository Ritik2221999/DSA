#include<bits/stdc++.h>
using namespace std;

void reverseArrayHelper(int start, int end, vector<int> &arr) {
    // base case -> 1
    if(start >= end)
        return;
        
    // do th small task -> 2
    swap(arr[start], arr[end]);
    
    // rest the recursion will handle -> 3
    reverseArrayHelper(start+1, end-1, arr);
}

void reverseArray(vector<int> &arr, int m) {
    reverseArrayHelper(m+1, arr.size()-1, arr);
}


int main() {
    int m;
    cout<<"Enter the position after which you have to reverse the array: "<<endl;
    cin>>m;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    
    reverseArray(arr, m);
    
    cout<<"The revsesal array after a specific position is: "<<endl;
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}