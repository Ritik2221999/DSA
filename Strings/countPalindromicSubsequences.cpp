#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int count(int i, int j, string str) {
    if(i > j)
        return 0;

    if(i == j)
        return 1;

    if(str[i] == str[j]) {
        return (1 + ((count(i+1, j, str))%MOD + (count(i, j-1, str))%MOD))%MOD;
    }
    else {
        return ((count(i+1, j, str))%MOD + (count(i, j-1, str))%MOD - (count(i+1, j-1, str))%MOD)%MOD;
    }
}

// top - down Approach
int solveRecMem(int i, int j, string &str, vector<vector<int> > &dp) {
//     base cases
    if(i > j)
        return 0;
    if(i == j)
        return 1;
//     step: 3)
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(str[i] == str[j]) {
        dp[i][j] = (1 + ((solveRecMem(i+1, j, str, dp))%MOD + (solveRecMem(i, j-1, str, dp))%MOD))%MOD;
    }
    else {
        dp[i][j] = ((solveRecMem(i+1, j, str, dp))%MOD + (solveRecMem(i, j-1, str, dp))%MOD - (solveRecMem(i+1, j-1, str, dp))%MOD)%MOD;
    }
    return dp[i][j];
}


int countPS(string str) {
    int i = 0;
    int n = str.length();
    
    // return count(i, j, str);
    
     //     step: 1)
    vector<vector<int> > dp(n, vector<int>(n+1, -1));
    
    return solveRecMem(i, n-1, str, dp);
}

int main() {
    string str = "aab";
    cout<<"The total number of palindromic subsequence is: "<<endl;
    
    cout<<countPS(str)<<endl;
    
    return 0;
}