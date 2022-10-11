#include<bits/stdc++.h>
using namespace std;

// Brute force approach
// Time Complexity -> O(2^n)

int LongestSubsequence(string str, int pos1, int pos2, int n) {
    // base case
    // if pos1 or pos2 reaches n, it means there are no further characters to consider, so return 0 

    if(pos1 == n || pos2 == n) {
        return 0;
    }    
    
    // If the two characters are equal and not occurring at the same index,
    // then increase the length of the longest repeating subsequence by 1
    if(pos1 != pos2 && str[pos1] == str[pos2]) {
        return 1+LongestSubsequence(str, pos1+1, pos2+1, n);
    }
    else {
        // return the maximum result from both the strings before current element and move to next element
        // i.e. max(dp[i-1][j], dp[i][j-1]) i -> pointer to first string, j -> pointer to second string
        return max(LongestSubsequence(str, pos1+1, pos2, n), 
        LongestSubsequence(str, pos1, pos2+1, n));
    }
}

int LongestRepeatingSubsequence(string str) {
    int pos1 = 0;
    int pos2 = 0;
    int n = str.length();
    
    return LongestSubsequence(str, pos1, pos2, n);
}

int main() {
    string str = "axxzxy";
    
    int ans = LongestRepeatingSubsequence(str);
    cout<<ans;
    return 0;
}



// approach - 2 -> top-Down approach
// Time Complexity -> O(n^2)

int LongestRepeatingSubsequence(string str, int pos1, int pos2, int n, vector<vector<int>> &dp) {
    // base case
    if(pos1 == n || pos2 == n)
        return 0;
        
    // if the state is already computes directly return from dp vector
    if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
    
    if(pos1 != pos2 && str[pos1] == str[pos2]) 
        return dp[pos1][pos2] = 1 + LongestRepeatingSubsequence(str, pos1+1, pos2+1, n, dp);
    else
        return dp[pos1][pos2] = max(LongestRepeatingSubsequence(str, pos1+1, pos2, n, dp),
                                    LongestRepeatingSubsequence(str, pos1, pos2+1, n, dp )
                                );
    
}

int main() {
    string str = "XXYZYVWW";
    
    vector<vector<int> > dp(9, vector<int>(9, -1));
    
    cout<<"The length of the longest repeating subsequence in the given string is: "<<endl;
    cout<<LongestRepeatingSubsequence(str, 0, 0, 8, dp);
}