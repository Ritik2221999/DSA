#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSquares(int N) {
        // code here
        int count = -1, i = 0, sq = 0;
        
        while(sq < N) {
            count++;
            i++;
            sq = i * i;
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}