#include<bits/stdc++.h>
using namespace std;

int hasArrayTwoCandidates(int arr[], int n, int x) {
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    
    for(auto itr=mp.begin(); itr != mp.end(); itr++) {
        int key = itr -> first;
        int val = itr -> second;
        
        int pair = x - key;
        if(pair == key) {  // so that element won't count itself twice again thats why we are checking
            if(val > 1)    // if that element is appeared again
                return true;
        }
        else {
            if(mp.find(pair) != mp.end())
                return true;
        }
    }
    return false;
}


int main() {
    int arr[] = {1, 4, 45, 6, 10, 8};
    int x = 16;
    
    cout<<"Intersection of two arrays is: "<<endl;
    cout<<hasArrayTwoCandidates(arr, 6, x);
    return 0;
}