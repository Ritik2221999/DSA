// https://www.codingninjas.com/codestudio/problems/all-unique-permutations_1094902

#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(n! * log(n!)
void uniquePerm(int pos, vector<int> &arr, int n, vector<vector<int> > &ans) {
//     base case
    if(pos == n) {
        ans.push_back(arr);
        return ;
    }

    unordered_set<int> m;
    for(int i=pos; i<n; i++) {
        if(m.find(arr[i]) != m.end()) continue;  // if element repeats continue
        m.insert(arr[i]);
        swap(arr[i], arr[pos]);
        uniquePerm(pos+1, arr, n, ans);
        swap(arr[i], arr[pos]); // backtracking
    }
}


vector<vector<int> > uniquePermutations(vector<int> &arr, int n) {
	// Write your code here.
    vector<vector<int> > ans;
    uniquePerm(0, arr, n, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    vector<vector<int> > result;
    result = uniquePermutations(arr, n);
    
    cout<<"The possible unique permutations is: "<<endl;
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }cout<<endl;
    }
    
    return 0;
}