#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(n! * log(n!)
void find(string str, int left, int right, set<string> &ans) {
    // base case
    if(left == right) {
        ans.insert(str);
        return;
    }
    else {
        for(int i=left; i<=right; i++) {
            swap(str[left], str[i]);
            
            find(str, left+1, right, ans);
            
            swap(str[left], str[i]);
        }
    }
}

vector<string> find_permutation(string str) {
    int n = str.length();
    int left = 0;
    int right = n-1;
    
    set<string> ans;
    vector<string> res;
    
    find(str, left, right, ans);
    
    for(auto x: ans) {
        res.push_back(x);
    }
    sort(res.begin(), res.end());
    
    return res;
}

int main() {
    string str = "ABC";
    
    vector<string> result;
    result = find_permutation(str);
    
    for(auto i: result) {
        cout<<i<<" ";
    }
    
    return 0;
}