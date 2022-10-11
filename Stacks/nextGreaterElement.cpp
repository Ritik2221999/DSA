// https://practice.geeksforgeeks.org/problems/next-larger-element/0
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        vector<long long> v;
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[i] >= st.top()) {
                st.pop();
            }
            
            if(st.size() == 0)
                v.push_back(-1);
                
            else {
                v.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}