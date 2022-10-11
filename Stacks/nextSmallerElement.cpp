// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        // Write your code here.
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--) {
            int curr = arr[i];
            
            while(s.top() >= curr) {
                s.pop();
            }
    //         ans is stack top
            ans[i] = s.top();
            s.push(curr);
        }
        return ans;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <int> res = obj.nextSmallerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}