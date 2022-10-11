// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        deque<long long int> dq;
        vector<long long int> ans;
        
        // process first window of size k
        for(int i=0; i<K; i++) {
            if(A[i] < 0)
                dq.push_back(i);
        }
        
        // store answer of first k sized window
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
        
        // process for remaining windows
        for(int i=K; i<N; i++) {
            // removal of outside window element which has been processed
            if(!dq.empty() && i - dq.front() >= K) {
                dq.pop_front();
            }
            
            // addition of front element index
            if(A[i] < 0)
                dq.push_back(i);
                
            // ans store 
            if(dq.size() > 0) {
                ans.push_back(A[dq.front()]);
            }
            else {
                ans.push_back(0);
            }
        }
        return ans;
 }