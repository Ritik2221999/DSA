#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    
    int i, j;
//  creater a matrix of dimension ((n+1) * (m+1))
    int LCS[len1+1][len2+1]; 
    
// fill zero'th row and zero'th column with zeros
    
//   for zero'th column
    for(int i=0; i<=len1; i++)
        LCS[i][0] = 0;
    
//  for zero'th row
    for(int j=0; j<=len2; j++)
        LCS[0][j] = 0;
    
    for(int i=1; i<=len1; i++) {
        for(int j=1; j<=len2; j++) {
//  i-1 and j-1 because of zero based indexing
            if(text1[i-1] == text2[j-1])   //  if both the characters match
                LCS[i][j] = 1 + LCS[i-1][j-1];
            
            else {  // mismatch
               LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]); 
            }
        }
    }
    return LCS[len1][len2];
}

int main() {
    string str1 = "abaaba";
    string str2 = "babbab";
    
    cout<<"The longest LCS is: "<<longestCommonSubsequence(str1, str2)<<endl;
    return 0;
}