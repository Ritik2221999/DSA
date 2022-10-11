#include<bits/stdc++.h>
using namespace std;

int find_median(vector<int> v) {
    sort(v.begin(), v.end());
    
    int n = v.size();
    int left = 0;
    int right = n-1;
    
    // for even size
    if(n%2 == 0) {
        int mid1 = (left + right)/2;
        int mid2 = mid1 + 1;
        
        int ans = (v[mid1] + v[mid2])/2;
        return ans;
    }
    // for odd length
    int mid = (left + right)/2;
    return v[mid];
}

int main() {
    vector<int> arr =   {90, 100, 78, 89, 67 }; //{56, 67, 30, 79};
    
    cout<<"median of array is: "<<find_median(arr);
    
    return 0;
}