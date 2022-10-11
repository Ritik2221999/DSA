// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
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
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}