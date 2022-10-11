// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        unordered_map<int, stack<int> > m;
        
        for(int i=0; i<2*e; i += 2) {
            // 1 2, 1 3, 1 4 -> A
            //   1           [4]
            // 2 3 4         [3]
            // stack of 1 -> [2]
            m[A[i]].push(A[i+1]);
        }
        
        for(int i=0; i<2*e; i+=2) {
            // 1 4, 1 3, 1 2
            if(m[B[i]].top() != B[i+1]) return 0;
            m[B[i]].pop();
        }
        return 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}