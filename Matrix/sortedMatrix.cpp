#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
       vector<int> vect;
       for(int i=0; i<N; i++) {
           for(int j=0; j<N; j++) {
               vect.push_back(Mat[i][j]);
           }
       }
       
       sort(vect.begin(), vect.end());
       int k = 0;
       
       vector<vector<int>> ans(N, vector<int> (N));
       for(int i=0; i<N; i++) {
           for(int j=0; j<N; j++) {
               ans[i][j] = vect[k++];
           }
       }
       return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
} 