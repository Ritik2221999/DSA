#include<bits/stdc++.h>
using namespace std;

// with hashing -> O(n^2)
void moreThanNByK(int arr[], int n, int k) {
    int x = n/k;
    
    unordered_map<int, int> freq;
    
    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
    }
    
    cout<<"The elements appears in array more than n/k is: "<<endl;
    for(auto i: freq) {
        if(i.second > x) {
            cout<<i.first<<", ";
        }
    }
}

int main() {
    int arr[13] = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
    int k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    
    moreThanNByK(arr, 13, k);
                 
    
    return 0;
}


// wihout hashing -> O(n^2)
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    
    int arr[n];
    cout<<"Enter the elements in array: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    
    int x = n/k;
    
    cout<<"The elements appears in array more than n/k is: "<<endl;
    for(int i=0; i<n; i++) {
        int count = 1;
        
        if(arr[i] != -1) {
            for(int j=i+1; j<n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1; // set the visited element to -1 to avoid repetition
                }
            }
        }
        
        if(count > x) cout<<arr[i]<<" ";
    }
    return 0;
}