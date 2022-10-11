// https://www.codingninjas.com/codestudio/problems/unique-subsets_3625236

#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(2^n)
void helper(int currElement, vector<int> &arr, int n, vector<int> &subString, vector<vector<int> > &ans) {
//     base case
    if(currElement >= n) {
        ans.push_back(subString);
        return ;
    }
//     including the element
    subString.push_back(arr[currElement]);
    helper(currElement+1, arr, n, subString, ans);
    subString.pop_back();
    
//     excluding the element
//     if consecutive elements are same just increment the iterator
    while(currElement+1 < n && arr[currElement] == arr[currElement+1]) currElement++;
    helper(currElement+1, arr, n, subString, ans);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<int> subString;
    vector<vector<int>> ans;
    
    helper(0, arr, n, subString, ans);
    sort(ans.begin(), ans.end());
    return ans;
    
}

int main() {
    vector<int> v = {1, 2, 3};
    int n = v.size();
    
    vector<vector<int> > result;
    result = uniqueSubsets(n, v);
    
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
