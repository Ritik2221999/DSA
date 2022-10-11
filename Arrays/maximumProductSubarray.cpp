#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(n^2)
// long long maxProduct(vector<int> arr, int n) {
//     long ans = arr[0];
    
//     for(int i=0; i<n; i++) {
//         long temp = arr[i];
        
//         for(int j=i+1; j<n; j++) {
//             if(temp == 0) continue;
            
//             if(temp > ans)
//                 ans = temp;
                
//             temp *= arr[j];
//         }
//         if(temp > ans)
//             ans = temp;
//     }
//     return ans;
// }

// Time Complexity -> O(n)

long long maxProduct(vector<int> arr, int n) {
    int ans =  arr[0];
    int ma = ans;
    int mi = ans;
    
    for(int i=1; i<n; i++) {
        if(arr[i] < 0)
            swap(ma, mi);
        ma = max(arr[i], ma*arr[i]);
        mi = min(arr[i], mi*arr[i]);
        ans = max(ans, ma);
    }
    return ans;
}

int main() {
    vector<int> arr = {6, -3, -10, 0, 2};
    
    int result = maxProduct(arr, 5);
    cout<<result;
    return 0;
}