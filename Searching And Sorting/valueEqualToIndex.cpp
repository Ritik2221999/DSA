#include<bits/stdc++.h>
using namespace std;

// Tine Complexity -> O(n)
vector<int> valueEqualToIndex(vector<int> &arr, int n) {
    vector<int> result;
    
    for(int i=0; i<n; i++) {
        int temp = i+1;
        if(arr[i] == temp)
            result.push_back(temp);
    }
    return result;
}

int main() {
    vector<int> arr = {15, 2, 45, 12, 7}; 
    int n = arr.size();

    vector<int> ans = valueEqualToIndex(arr, n);
    
    cout<<"value equal to index is: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}