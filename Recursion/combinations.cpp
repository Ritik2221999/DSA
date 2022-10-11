// https://www.codingninjas.com/codestudio/problems/combinations_3625257

#include<bits/stdc++.h>
using namespace std;

void helper(int i, int n, int k, vector<int> &subSet, vector<vector<int>> &ans) {
    
//     base case
    if(k == 0) {
        ans.push_back(subSet);
        return ;
    }
        
    if(i > n) return ;
//     push the ith element
    subSet.push_back(i);
    helper(i+1, n, k-1, subSet, ans);
    
//     skip the ith element
    subSet.pop_back();
    helper(i+1, n, k, subSet, ans);
}

vector<vector<int>> combinations(int n, int k)
{
    // Write your code here.
    vector<int> subSet;
    vector<vector<int> > ans;
    helper(1, n, k, subSet, ans);
    return ans;
}

int main() {
    int n, k;
    vector<vector<int> > result;
    cin>>n;
    cin>>k;

    result = combinations(n, k);
    cout<<"possible combinations of k numbers out of the range 1 to N: "<<endl;
        for(int i=0; i<result.size(); i++) {
            for(int j=0; j<result[i].size(); j++) {
                cout<<result[i][j]<<" ";
            }cout<<endl;
        }
    return 0;
}