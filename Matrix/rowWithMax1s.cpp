#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
    int ans = -1;
    int count = 0;
    
    for(int i=0; i<n; i++) {
        int count1 = 0;
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 1) {
                count1++;
            }
        }
        if(count1 > count) {
            ans = i;
            count = count1;
        }
    }
    return ans;
}

int main() {
    int n=4, m=4;
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
    };
    
    cout<<"The row that has Max no of 1's is: "<<rowWithMax1s(arr, n, m);
    return 0;
}