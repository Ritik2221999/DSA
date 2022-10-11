#include<bits/stdc++.h>
using namespace std;

int firstRepeated(int *arr, int n) {
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++)
        mp[arr[i]]++;
    
    for(int i=0; i<n; i++) {
        int key = arr[i];
        auto temp = mp.find(key);
        if(temp -> second > 1)
            return i+1; // 1-based indexing thats why adding + 1
    }
    return -1;
}

int main() {
    int arr[] = {1, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"First non- repeating element is: "<<endl;
    cout<<firstRepeated(arr, n);
    return 0;
}