#include<bits/stdc++.h>
using namespace std;

// naive Approach
int MinMax(int *arr, int k, int n) {
    int sum = 0;
    
    for(int i=0; i<=(n-k); i++) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int j=i; j<(i+k); j++) {
            mini = min(mini, arr[j]);
            maxi = max(maxi, arr[j]);
        }
        sum += (mini + maxi);
    }
    return sum;
}

int main() {
    int arr[] = {5, 9, 8, 3, -4, 2, 1, -5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    
    cout<<"sum of minimum and maximum of size: "<<k<<" is: "<<endl;
    cout<<MinMax(arr, k, n);
    
}



// Optimized Approach
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k) {
    deque<int> maxi(k);
    deque<int> mini(k);
    
    // findinf the first maximum and minimum in first k sized window
    
    for(int i=0; i<k; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
            
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
            
        maxi.push_back(i);
        mini.push_back(i);
    }
    
    int ans = 0;
    for(int i=k; i<n; i++) {
        ans += arr[maxi.front()] + arr[mini.front()];
        
        // next window
        // removal of processed element
        while(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
            
        while(!mini.empty() && i - mini.front() >= k)
            mini.pop_front();
          
        // addition of next element of new k sized window 
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
            
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
            
        maxi.push_back(i);
        mini.push_back(i);
    }
    
    // to consider the last window
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
}

int main() {
    
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    
    cout<<"the sum of maximim and minimum elements of all subarrays if size: "<<k<<" is: "<<endl;
    cout<<solve(arr, 7, k)<<endl;
    
    return 0;
}