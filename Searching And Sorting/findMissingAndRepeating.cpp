#include<bits/stdc++.h>
using namespace std;

int *findTwoElements(int *arr, int n) {
    int x = n + 1;
    
    int substitute[x] = {0};
    
    int *ans = new int[2];
    
    for(int i=0; i<n; i++) {
        substitute[arr[i]]++;
    }
    
    // since numbers are from 1 to N
    for(int i=1; i<=n; i++) {
        if(substitute[i] == 0)
            ans[1] = i;
        else if(substitute[i] > 1)
            ans[0] = i;
    }
    return ans;
}

int main() {
    int arr[] = {1, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto ans = findTwoElements(arr, n);
    
    cout<<ans[0]<<" "<<ans[1]<<" "<<endl;
    return 0;
}