#include<bits/stdc++.h>
using namespace std;

// fill lps[] for given par[0 .. M-1]
void computeLPSArray(char* pat, int M, int* lps) {
    // length of the previous longest prefix suffix
    int len = 0;
    
    lps[0] = 0; // lps[0] is always 0
    
    int i = 1;
    
    while(i < M) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// print occurences of pat[] in txt[]
void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    
    // create lps[] that will hold the longest prefix suffix values for pattern
    int lps[M];
    
    // preprocesses the pattern(calculate lps[] array)
    computeLPSArray(pat, M, lps);
    
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    
    while(i < N) {
        if(pat[j] == txt[i]) {
            j++;
            i++;
        }
        if(j == M) {
            cout<<"pattern found at index: "<<i-j;
            j = lps[j-1];
        }
        // mismatch after matches
        else if (i < N && pat[j] != txt[i]) {
            if(j != 0) 
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}



int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}