// https://www.codingninjas.com/codestudio/problems/combination-sum_981296

#include<bits/stdc++.h>
using namespace std;

void help(int i, vector<int> &arr, int B, int &sumTillNow, vector<int> &subset, vector<vector<int >> &ans) {
//     base case
    if(sumTillNow == B) {
        ans.push_back(subset);
        return ;
    }
    if(sumTillNow > B) return ;
    
    if(i >= arr.size()) return ;
    
//     skip the curr element
    help(i+1, arr, B, sumTillNow, subset, ans);
    
//     tke ther i-th element
    sumTillNow += arr[i];
    subset.push_back(arr[i]);
    help(i, arr, B, sumTillNow, subset, ans);
    
//     bactracking
    sumTillNow -= arr[i];
    subset.pop_back();  
}


vector<vector<int>> combSum(vector<int>& ARR, int B)
{
	// Write your code here
	// Return a vector of sorted vectors/combinations
    vector<vector<int> > ans;
    vector<int> subset;
    int sum = 0;
    sort(ARR.begin(), ARR.end());
    help(0, ARR, B, sum, subset, ans);
    return ans;
}

int main() {
    int n, b;
    cout<<"Enter the number of elements in array: "<<endl;
    cin>>n;
    
    cout<<"Enter the sum :"<<endl;
    cin>>b;
    
    vector<int> arr(n);
    
    cout<<"Enter the elements in vector: "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    vector<vector<int>> result = combSum(arr, b);
    
    cout<<"all unique combinations in the array whose sum is equal to: "<<b<<" is: "<<endl;
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }cout<<"= "<<b<<endl;
        cout<<endl;
    }
    return 0;
}