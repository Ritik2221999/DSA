// https://www.codingninjas.com/codestudio/problems/combination-sum-ii_1112622

#include<bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> &arr, int sum, vector<int> &subset, vector<vector<int> > &ans, int target) {
//     base cases
    if(sum == target) {
        ans.push_back(subset);
        return ;
    }
    if(sum > target) return ;
    
    if(i == arr.size()) return ;
    
//     picking the element
    subset.push_back(arr[i]);
    sum += arr[i];
    helper(i+1, arr, sum, subset, ans, target);
    subset.pop_back();
    sum -= arr[i];
    
    while(i + 1 < arr.size() && arr[i] == arr[i+1]) i++;
    helper(i+1, arr, sum, subset, ans, target);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    vector<int> subset;
    vector<vector<int> > ans;
    int sum = 0;
    sort(arr.begin(), arr.end());
    helper(0, arr, sum, subset, ans, target);
    return ans;
    
}


int main() {
    int n, b;
    cout<<"Enter the number of elements in array: "<<endl;
    cin>>n;
    
    cout<<"Enter the target sum :"<<endl;
    cin>>b;
    
    vector<int> arr(n);
    
    cout<<"Enter the elements in vector: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    vector<vector<int>> result = combinationSum2(arr, n, b);
    
    cout<<"all unique combinations in the array whose sum is equal to: "<<b<<" is: "<<endl;
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }cout<<"= "<<b<<endl;
        cout<<endl;
    }
    return 0;
}