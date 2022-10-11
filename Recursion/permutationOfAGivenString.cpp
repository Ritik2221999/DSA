#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(n! * log(n!)
void perm(int pos, string &str, vector<string> &ans) {
//     base case
    if(pos >= str.size()) {
        ans.push_back(str);
        return ;
    }
    for(int i=pos; i<str.size(); i++) {
         swap(str[i], str[pos]);
        perm(pos+1, str, ans);
        swap(str[i], str[pos]); // backtracking
    }
}

vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string> ans;
    perm(0, str, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    string str = "ABC";
    
    vector<string> result;
    result = generatePermutations(str);
    
    for(auto i: result) {
        cout<<i<<" ";
    }
    
    return 0;
}