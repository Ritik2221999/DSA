#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n) {
    int sum = 0;
    unordered_set<int> s;
    
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum == 0)
            return true;
        
        if(s.find(sum) != s.end())
            return true;
        else
            s.insert(sum);
    }
    return false;
}

void printAllSubarrays(int nums[], int n) {
    
    for(int i=0; i<n; i++) {
        int sum = 0;
        
        for(int j=i; j<n; j++) {
            sum += nums[j];
            
            // if the sum is seen before, we have found a subarray
            // with zero-sum
            if(sum == 0)
                cout<<"subarray from indexes [" << i<<"..."<<j<<"]\n";
        }
    }
}

int main() {
    int arr[5] = {4, 2, -3, 1, 6};
    
    printAllSubarrays(arr, 5);
    
    bool res = subArrayExists(arr, 5);
    if(res)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

