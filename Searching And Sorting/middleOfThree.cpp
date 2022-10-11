// https://practice.geeksforgeeks.org/problems/middle-of-three2926/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        if(A > B && A < C || A > C && A < B)
            return A;
        else if(B > A && B < C || B > C && B < A)
            return B;
        else
            return C;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
} 